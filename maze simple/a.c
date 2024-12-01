#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INNER_GRID_WIDTH 4
#define INNER_GRID_HEIGHT 3
#define GRID_WIDTH (2 * INNER_GRID_WIDTH + 1)
#define GRID_HEIGHT (2 * INNER_GRID_HEIGHT + 1)
#define START_X 1 // coordonnée de départ. doit être impaire et dans la grille
#define START_Y 1

// un mur c'est les coordonnées d'une case + une direction
typedef struct {int x, y, d;} t_wall;

// les directions
// 0 haut
// 1 bas
// 2 gauche
// 3 droite

// delta x et y pour avoir les coordonnées d'une case voisine dans l'inner grid sachant une direction.
// par exemple, pour x et y (dans l'inner grid), x + DX[0], y + DY[0] donne la case en haut de x, y
const int DX[] = {0, 0, -2, 2};
const int DY[] = {-2, 2, 0, 0};

typedef struct
{
	char	**grid;
	t_wall	*walls;
}	t_data;

void deep_free(void **p)
{
	if (p == NULL)
		return ;
	for (int i = 0; p[i] != NULL; i++)
		free(p[i]);
	free(p);
}

void free_all(t_data *data)
{
	deep_free((void **)data->grid);
	free(data->walls);
}

void error_exit(t_data *data)
{
	free_all(data);
	exit(1);
}

void init(t_data *data)
{
	srand(time(NULL));
	data->grid = calloc(GRID_WIDTH + 1, sizeof(char *));
	if (data->grid == NULL)
		error_exit(data);
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		data->grid[i] = calloc(GRID_HEIGHT + 1, sizeof(char));
		if (data->grid[i] == NULL)
			error_exit(data);
	}
	for (int i = 0; i < GRID_WIDTH; i++)
		for (int j = 0; j < GRID_HEIGHT; j++)
			data->grid[i][j] = '1';
	data->grid[START_X][START_Y] = 'S';
	data->walls = calloc(4 * INNER_GRID_WIDTH * INNER_GRID_HEIGHT + 1, sizeof(t_wall));
	if (data->walls == NULL)
		error_exit(data);
}

int is_in_inner_grid(int x, int y)
{
    return x % 2 == 1 && x > 0 && x < GRID_WIDTH - 1
	&& y % 2 == 1 && y > 0 && y < GRID_HEIGHT - 1;
}

void generate(t_data *data)
{
	int wall_count = 0; // pour se déplacer dans walls
	
	// coordonnées d'une case voisine
	int nx;
	int ny;
	int d; // direction de 0 à 3 à mettre dans DX et DY

	// coordonnées des murs d'une case voisine
	int nnx;
	int nny;

    // ajouter les murs voisins au start dans walls
    for (d = 0; d < 4; d++) {
        nx = START_X + DX[d];
        ny = START_Y + DY[d];
        if (is_in_inner_grid(nx, ny))
            data->walls[wall_count++] = (t_wall){START_X, START_Y, d};
    }

    while (wall_count > 0) // tant qu'il y a des murs à ouvrir 
	{
        // Prendre un mur au hasard
        int i = rand() % wall_count;
        t_wall wall = data->walls[i];
        data->walls[i] = data->walls[--wall_count]; // Supprimer le mur

        // Calculer la cellule voisine
        nx = wall.x + DX[wall.d];
        ny = wall.y + DY[wall.d];

        if (is_in_inner_grid(nx, ny) && data->grid[nx][ny] == '1') // si la cellule voisine est dans l'inner grid et n'a pas encore été changée en chemin
		{
			// on va ouvre le mur et on ajoute la cellule voisine au chemin
            data->grid[wall.x + DX[wall.d] / 2][wall.y + DY[wall.d] / 2] = '0';
            data->grid[nx][ny] = '0';

            // on ajoute les murs de la nouvelle cellule à walls
            for (d = 0; d < 4; d++) {
                int nnx = nx + DX[d];
                int nny = ny + DY[d];
                if (is_in_inner_grid(nnx, nny) && data->grid[nnx][nny] == '1')
                    data->walls[wall_count++] = (t_wall){nx, ny, d};
            }
        }
    }
}

void print(t_data *data)
{
    for (int y = 0; y < GRID_HEIGHT; y++)
	{
        for (int x = 0; x < GRID_WIDTH; x++) {
            printf("%c", data->grid[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    t_data data;

	init(&data);
    generate(&data);
    print(&data);
	free_all(&data);
    return 0;
}
