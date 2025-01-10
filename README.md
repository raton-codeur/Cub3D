# à faire dans les bonus

- porte
- animation

# à faire partout

- revoir makefile
- revoir init_game.c + bonus

## check leaks

- maze trop grand

# amélioration du maze

- colorier la case d'arriver
- stop le jeu quand on arrive

# petites amélioration pour le parsing

- le message d'erreur est incorrect lorsqu'un caractère invalide est hors de la carte. on a toujours "map is not closed". exemple :
```
1111
1001x
1001
...
```

il faudrait un message "la map doit être entourée de murs".

- de même, on pourra utiliser ce message dans le cas :
```
111
1N1x
111
```
avec un espace à la place du `x`

- message incorrect lorsque la map n'est pas à la fin du fichier

- il manque un message d'erreur lorsque l'identifiant d'un élément fait plus de 2 caractères de long

- les messages "Too many textures" et "Too many colors" sont pas terribles. il faudrait un truc comme "répétition de texture" / "répétition de couleur". je propose de bloquer tous les éléments qui ne sont pas requis par notre code

- je comprends pas le message "Invalid texture file name". "missing texture" ne suffit pas ?

- il manque un "Error\n" dans le cas : `./cub3D "    ../maps/simple.cub"`. Il faut appeler `perror_exit`

- vérifier que les maps ne sont pas discontinues ? par exemple, ceci est pour l'instant correct :
```
111 1
1N1
111
```
alors que ceci est incorrect :
```
111
1N1
111

1
```
