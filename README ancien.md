
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

on a mini box size : le nombre de pixels de la minimap qui correspondent à 10 cases

# render minimap

(x, y) parcourt les pixels de la minimap.

mini_base, c'est dir tourné de 90° à gauche.
mini_perp est perpendiculaire à mini_base. c'est mini_base tourné de 90° à gauche.

(x, y) correspond, dans la base (mini_base, mini_perp), à (mini_x, mini_y).
notamment, (minimapwidth / 2, minimapwidth / 2) correspond à (pos x, pos y).

on veut trouver (xd, yd) à partir de (x, y).

(xd, yd) est (pos_x, pos_y) + une certaine combinaison de mini_base et mini_perp dont les coefficients sont (mini_x, mini_y).

explications :

on sait que la minimap fait 10 unités de jeu de large.
- mini_box_size = minimap_width / 10
- [ tant d'unités de jeu ] * mini_box_size = [ tant de pixels de minimap ]

on peut ramener tout (x, y) au centre de l'image avec (x - minimap_width / 2, y - minimap_width / 2). on obtient des coordonnées en pixels dans la minimap par rapport au centre de la minimap.
et, en divisant ça par mini_box_size, on obtient (mini_x, mini_y), c'est a dire, on obtient le déplacement relatif par rapport au joueur, dans le jeu, que représente (x, y).

rappel : la combinaison linéaire des vecteurs (ax, ay) et (bx, by) avec les coefficients (c1, c2) est :
- x = c1 ax + c2 bx
- y = c1 ay + c2 by

donc, pour combiner mini_base et mini_perp avec les coefficients (mini_x, mini_y) on fait :
- en x : mini_x * mini_base_x + mini_y * mini_perp_x
- en y : mini_x * mini_base_y + mini_y * mini_perp_y

# passer de coordonnées xd, yd à x, y

