# Avalam - First year's project at Ecole Centrale de Lille

This game is our first year's project at Ecole Centrale de Lille (IG2I).
We decided to port Avalam's board game on computer.
We added some IA and are trying to get it as optimized as possible.
It's still under development.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
SDL2 -> no tutorial for now
```

### Installing

A step by step series of examples that tell you have to get a development env running

First compile for your environment

```
g++ src/main.cpp src/classes/*/*.cpp -o avalam.exe
```

Give it rights

```
chmod +x avalam.exe
```

And execute

```
./avalam.exe
```

Here is an output-overview of what it currently does.

```
Running build/release-0.1.2.exe...
=========================
======== BOARD ========
=========================
=    ==0== ==1== ==2== ==3== ==4== ==5== ==6== ==7== ==8==  =
= 0:             (0:1) (0:1)                                =
= 1:       (1:1) (1:1) (1:1) (1:1)                          =
= 2:       (0:1) (0:1) (0:1) (0:1) (0:1) (0:1)              =
= 3:       (1:1) (1:1) (1:1) (1:1) (1:1) (1:1) (1:1) (1:1)  =
= 4: (0:1) (0:1) (0:1) (0:1)       (0:1) (0:1) (0:1) (0:1)  =
= 5: (1:1) (1:1) (1:1) (1:1) (1:1) (1:1) (1:1) (1:1)        =
= 6:             (0:1) (0:1) (0:1) (0:1) (0:1) (0:1)        =
= 7:                         (1:1) (1:1) (1:1) (1:1)        =
= 8:                               (0:1) (0:1)              =
==== 0 : 24 | 1 : 24 ====
Bot John initialised ! (team : 0)
David has joined the game ! (team : 1)
=========================
======== PLATEAU ========
=========================
=    ==0== ==1== ==2== ==3== ==4== ==5== ==6== ==7== ==8==  =
= 0:             (0:1) (0:1)                                =
= 1:       (1:1) (1:1) (1:1) (1:1)                          =
= 2:       (0:1) (0:1) (0:1) (0:1) (0:1) (0:1)              =
= 3:       (1:1) (1:1) (1:1) (1:1) (1:1) (1:1) (1:1) (1:1)  =
= 4: (0:1) (0:1) (0:1) (0:1)       (0:1) (0:1) (0:1) (0:1)  =
= 5: (1:1) (1:1) (1:1) (1:1) (1:1) (1:1) (1:1) (1:1)        =
= 6:             (0:1) (0:1) (0:1) (0:1) (0:1) (0:1)        =
= 7:                         (1:1) (1:1) (1:1) (1:1)        =
= 8:                               (0:1) (0:1)              =
==== 0 : 24 | 1 : 24 ====


```

## Built With

* [C++](http://www.cplusplus.com/) - The language
* [SDL2](https://www.libsdl.org/) - Simple DirectMedia Layer 2 Library

## Contributing

Please feel free to share what you experienced with the game.
We're also very happy to hear your improvement ideas.

## Versioning

We use our own algorithm about versioning (simple increment).

## Authors

* **Martin Joly** - *Student* - [snwfdhmp](https://github.com/snwfdhmp)

* **Landry Monga** - *Student* - [lvndry](https://github.com/lvndry)

See also the list of [contributors](https://github.com/snwfdhmp/MPI/contributors) who participated in this project.

## License

This project is not under any license yet.
