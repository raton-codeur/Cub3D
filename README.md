
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

### recopier un carré

on veut recopier le carré autour du joueur sur la minimap

on a data->x et data->y qui parcourent la minimap
par exemple, data->x va de 0 à data->minimap->width

pour savoir a quelles coordonnées du jeu correspondent un (x, y) donné, on utilise un (xd, yd)
par exemple, xd commence à (pos_x - 5) et fini à (pos_x + 5)

on sait que data->minimap->width correspond à une longueur de 10 dans le jeu.
on divise 10 par data->minimap->width pour avoir la valeur d'incrément de xd.
on appelle ça minimmap_step, défini une bonne fois pour toute dans le init_game.

### rotation

ce n'est plus juste une incrémentation normale de xd et de yd. il faut utiliser dir_x et dir_y.

on appelle ça mini_step_x et mini_step_y, qui dépendent donc de dir_x et dir_y.

la valeur d'incrémentation de xd dépend de dir_x.

on sait que le vecteur dir correspond à 1 case unité.

on sait que 10 unités correspondent à data->minimap->width
donc 10 / data->minimap->width unités correspondent à l'incrémentation qu'on fait dans le jeu



