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

# Explication (French only)

## Présentation du repo

Ce repo correspond au projet MPI (projet C de 1ère année à IG2I (Ecole Centrale de Lille)).

Le principe du projet est de coder une version jeu vidéo du jeu de stratégie "Avalam".

## Principe du jeu

Les règles et principes du jeu sont exprimés dans cette vidéo par le créateur du jeu.

[![https://www.youtube.com/watch?v=DbZIvQSyFvA](https://img.youtube.com/vi/DbZIvQSyFvA/0.jpg)](https://www.youtube.com/watch?v=DbZIvQSyFvA)

## Principe de la version jeu vidéo

Les règles du jeu restent les même. Néanmoins nous avons implémenté 3 différents modes de jeu :

- Humain vs Humain :
  2 joueurs humains s'affrontent au tour par tour, en déplaçant les pions à l'aide de la souris
- Humain vs IA
  1 joueur humain contre une intelligence artificielle s'affrontent. L'intelligence artificielle joue de manière automatisée le meilleur mouvement qu'elle peut prédire.
- IA vs IA
  2 IA s'affrontent. L'utilisateur voit de déroulement de la partie et peut l'arrêter, l'accélérer, la ralentir, pour pouvoir observer la manière de jouer de l'IA.
  
## Contraintes

Langages :
    - C
    - C++
   
Librairies :
    - SDL2
    
Compilation :
    - Unix (gcc/g++)
  
 ## Organisation du projet
 
 [![OVERVIEW](https://preview.ibb.co/c9Y7vk/Capture_d_e_cran_2017_04_28_a_19_15_17.png)](https://github.com/snwfdhmp/avalam-ai-game/)
 
Le projet est divisé en plusieurs répertoires :

- [<code>build</code>](https://github.com/snwfdhmp/avalam-ai-game/tree/master/build)
  Tous nos builds sont sauvegardés dans ce dossier comme tel :
  
  [![OVERVIEW](https://preview.ibb.co/eWkLFk/Capture_d_e_cran_2017_04_28_a_19_29_09.png)](https://github.com/snwfdhmp/avalam-ai-game/tree/master/build)
  
  Le versioning est géré par l'utilitaire [<code>compile</code>](https://github.com/snwfdhmp/avalam-ai-game/tree/master/compile) que nous avons créé.
  
- [<code>config</code>](https://github.com/snwfdhmp/avalam-ai-game/tree/master/config)
  cat-variables pour le fichier <code>compile</code> et peut-être pour d'autres choses plus tard
  
  [![OVERVIEW](https://preview.ibb.co/jsLnvk/Capture_d_e_cran_2017_04_28_a_19_28_53.png)](https://github.com/snwfdhmp/avalam-ai-game/tree/master/config)
  
- [<code>junk</code>](https://github.com/snwfdhmp/avalam-ai-game/tree/master/junk)
  Quelques scripts qui nous on servit et qu'on ne supprime pas pour le moment. Ils ne font pas partie du code source
  
  [![OVERVIEW](https://preview.ibb.co/d7e2T5/Capture_d_e_cran_2017_04_28_a_19_29_23.png)](https://github.com/snwfdhmp/avalam-ai-game/tree/master/junk)
  
- [<code>logs</code>](https://github.com/snwfdhmp/avalam-ai-game/tree/master/logs)
  Logs de compilation fournis par <code>compile</code> et surement d'autres par la suite.
  
  [![OVERVIEW](https://preview.ibb.co/dF8J1Q/Capture_d_e_cran_2017_04_28_a_19_29_40.png)](https://github.com/snwfdhmp/avalam-ai-game/tree/master/logs)
  
- [<code>src</code>](https://github.com/snwfdhmp/avalam-ai-game/tree/master/src)
  Répertoire des sources. Il est organisé comme tel :
  
  [![OVERVIEW](https://preview.ibb.co/fCQLFk/Capture_d_e_cran_2017_04_28_a_19_30_02.png)](https://github.com/snwfdhmp/avalam-ai-game/tree/master/src)
  
  - [<code>main.cpp</code>](https://github.com/snwfdhmp/avalam-ai-game/tree/master/src/main.cpp)
    Fichier principal
  - [<code>classes</code>](https://github.com/snwfdhmp/avalam-ai-game/tree/master/src/classes)
    Contient toutes les classes que nous avons codées pour le projet.
    Chaque classe est représentée par un dossier à son nom contenant au moins
      - <code>*className*.class.cpp</code> => contient les implémentations de fonctions de la classe
      - <code>*className*.class.cpp</code> => contient le prototype de la classe
      - <code>*className*.test.cpp</code> => tests unitaires pour la classe
      
    [![OVERVIEW](https://preview.ibb.co/mth0Fk/Capture_d_e_cran_2017_04_28_a_19_30_14.png)](https://github.com/snwfdhmp/avalam-ai-game/tree/master/src/classes/MovePlan)
    
- [<code>compile</code>](https://github.com/snwfdhmp/avalam-ai-game/tree/master/compile)
  Shell-script utilisé pour la compilation, les logs, le versioning, etc.

- Compilation windows : "g++ -I.\include -L.\lib src/*/*.class.cpp src/landry_main.cpp -lSDL2 -lSDL2main -lSDL2.dll"
