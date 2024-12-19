
# partie obligatoire

# ajouter pour les bonus

- souris
- touches haut bas
- fog
- maze
- portes
- animations ?
- couleurs à la place des murs ?

# à faire

modifier les touches haut et bas pour épouser le haut et bas comme avec la souris

# retour sur la minimap

on init la largeur de la minimap à [ hauteur de la fenêtre / 4 ]

largeur de la minimap <-> 10 cases

## dans main hook

si config = 2, on dessine la minimap

## dans le dda, render for x

si config = 1, on dessine un rayon dans la map
sinon si config = 2, on dessine un rayon dans la minimap

## dessiner une minimap simple toujours orienté au nord qui suit le joueur

### analyse du code de jason

on a theta, l'angle de vision

on initialise start aux coordonnées en pixels du carré qui est autour du joueur

on va copier tout ce carré de pixels dans la minimap

### réfléchis

on veut recopier le carré autour du joueur sur la minimap

on a data->x et data->y qui parcourent la minimap
par exemple, data->x va de 0 à data->minimap->width

pour savoir a quelles coordonnées du jeu correspondent un (x, y) donné, on utilise un (xd, yd)
par exemple, xd commence à (pos_x - 5) et fini à (pos_x + 5)

on sait que data->minimap->width correspond à une longueur de 10 dans le jeu.
on divise 10 par data->minimap->width pour avoir la valeur d'incrément de xd.
on appelle ça minimmap_step, défini une bonne fois pour toute dans le init_game.


de combien doit on incrémenter x pour qu'il parcourt les 10 cases en data->minimap->width itération ?
10 / data->minimap->width !
pour que x parcourt les 10 cases en data->minimap->width itération, il faut l'incrémenter de 10 / data->minimap->width à chaque fois.




