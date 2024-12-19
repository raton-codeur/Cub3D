
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

