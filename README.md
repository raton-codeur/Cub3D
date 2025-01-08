# à faire dans les bonus

- maze
- animation porte

# à faire partout

- revoir la complétion du vide par des murs dans une map en escalier
- check leaks

- erreur non détectée :
```
[0] ~/Documents/42/cub3d/repo % ./cub3D "../maps/simple.cub blabla"
[0] ~/Documents/42/cub3d/repo % 
```

- le message d'erreur est incorrect lorsqu'un caractère invalide est hors de la carte. on a toujours "map is not closed". exemple :
```
1111
1001x
1001
...
```

- il faut limiter la box size de la map à celui de la minimap

- le message d'erreur pour ça n'est pas très logique :
```
111
1N1x
111
```
avec un espace à la place du `x`


