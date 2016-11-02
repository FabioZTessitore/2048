# 2048

Il gioco 2048 in tre versioni: console, ncurses, gtk.

## Installazione

### Download
```bash
$ git clone https://github.com/FabioZTessitore/2048.git
```

### Compilazione

Assicurarsi di avere le librerie ncurses
```bash
$ sudo apt-get update
$ sudo apt-get install libncurses5-dev
```

Assicurarsi di avere le librerie gtk (e pkg-config)
```bash
$ sudo apt-get update
$ sudo apt-get install pkg-config libgtk-3-dev
```

Assicurarsi di essere nella directory `2048/C` e utilizzare cmake
```
$ cd 2048/C
$ mkdir build
$ cd build
$ cmake ..
$ make
```

All'interno della directory build verranno create le directory `console`, `ncurses` e `gtk`, ognuna contenente l'eseguibile nella specifica versione.

### Esecuzione
```bash
$ ./ncurses/2048_ncurses
```
