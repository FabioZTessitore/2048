# 2048

Il gioco 2048 in tre versioni: console, ncurses, gtk.

## Installazione

### Download
```bash
$ git clone https://github.com/FabioZTessitore/2048.git
```

### Compilazione

#### Compilazione della versione console
```bash
$ make 2040_console
```

#### Compilazione della versione ncurses
Assicurarsi di avere le librerie ncurses
```bash
$ sudo apt-get update
$ sudo apt-get install libncurses5-dev
```
```bash
$ make 2048_ncurses
```

#### Compilazione della versione gtk
Assicurarsi di avere le librerie gtk
```bash
$ sudo apt-get update
$ sudo apt-get install libgtk-3-dev
```
```bash
$ make 2048_gtk
```

## Esecuzione
```bash
$ ./2048
```
