# Push Swap
This activity has been created as part of the 42 curriculum by <hugodavid-42> <psi-mous> psi-mous and hdavid

## Description
Push_swap is a project that sorts a stack of integers using a restricted set of operations.  
The challenge is to design an efficient algorithm that minimizes the number of moves required to sort the data. It will count the operations and print the movements used.


## Instructions

Compile with `make` and lunch the program with `./push_swap`.
All the options :
* `--simple` sort with the simples algos (Sort3 / Sort5 / Insertion sort) in [easy_algos.c](easy_algos.c)
* `--medium` sort with the medium algo (chunk sort) in [medium_algo.c](medium_algo.c)
* `--complex` sort with the complex algo (radix) in [complex_algo.c](complex_algo.c)
* `--adaptative`
* `--count_only` don't print the operations but only the count of operations
* `--bench` print all the informations about the sorting method used.

Example :

```bash
make
```
```bash
./push_swap --bench --adaptative "9 6 4 7 2"
```
or
```bash
./push_swap --bench --adaptative 9 6 4 7 2
```
return

```bash
[bench] disorder: 33.33%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 9
[bench] sa: 0 sb: 0 ss: 0 pa: 4 pb: 4
[bench] ra: 1 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```
Without options

```bash
./push_swap 3 2 1
```
return
```bash
sa
rra
```

## Choice of the algorithms

**Big-O Complexity**

<p align="center">
  <img src="https://media.licdn.com/dms/image/v2/D4E12AQEvsKZNftrL5w/article-cover_image-shrink_720_1280/article-cover_image-shrink_720_1280/0/1734702748422?e=2147483647&v=beta&t=Mp0AfdcOaVE6TQlsFmj-CIw9i9C0hXvAWk61IYqeH9w" alt="Image centrée" width="500"/>
</p>

* Insertion sort -> O(n^2)
* Chunk sort -> O(n√n)
* Radix -> O(log(n))

### Movements authorized

- Two stacks (`a` and `b`) used for sorting.
- Limited set of operations:
  - `sa` / `sb` / `ss` → swap the top elements
  - `pa` / `pb` → push elements between stacks
  - `ra` / `rb` / `rr` → rotate stack upwards
  - `rra` / `rrb` / `rrr` → rotate stack downwards
- Input validation (only integers, no duplicates).
- Optimized sorting algorithm for different input sizes.

```mermaid
flowchart TB
    %% =========================
    %% Piles A et B (top -> bottom)
    %% =========================
    subgraph A[Pile A]
        AT[Top A]
        A2[second bloc]
        AB[Bottom A]
    end

    subgraph B[Pile B]
        BT[Top B]
        B2[second bloc]
        BB[Bottom B]
    end

    %% =========================
    %% SWAPS : sa / sb / ss
    %% =========================
    AT -- sa --> A2
    A2 -- sa --> AT

    BT -- sb --> B2
    B2 -- sb --> BT

    %% ss applique sa et sb simultanément (représentation pointillée)
    AT -. ss .-> A2
    BT -. ss .-> B2

    %% =========================
    %% PUSH : pa / pb
    %% =========================
    BT -- pa: top B -> A --> AT
    AT -- pb: top A -> B --> BT

    %% =========================
    %% ROTATIONS vers le haut : ra / rb / rr
    %% (le top descend en bas)
    %% =========================
    AT -- ra --> AB
    BT -- rb --> BB
    AT -. rr .-> AB
    BT -. rr .-> BB

    %% =========================
    %% ROTATIONS vers le bas : rra / rrb / rrr
    %% (le bottom remonte en haut)
    %% =========================
    AB -- rra --> AT
    BB -- rrb --> BT
    AB -. rrr .-> AT
    BB -. rrr .-> BT

    %% =========================
    %% Styles pour distinguer les catégories
    %% =========================
    classDef swap stroke:#2563eb,stroke-width:2px,color:#2563eb
    classDef push stroke:#f59e0b,stroke-width:2px,color:#f59e0b
    classDef rotUp stroke:#10b981,stroke-width:2px,color:#10b981
    classDef rotDown stroke:#ef4444,stroke-width:2px,color:#ef4444
    classDef combo stroke:#8b5cf6,stroke-width:2px,color:#8b5cf6

    %% Assigner les styles par index d'arêtes (ordre de déclaration)
    %% Swaps (sa/sb): liens 0..3 ; ss: 4..5
    linkStyle 0,1,2,3 stroke:#2563eb,stroke-width:2px
    linkStyle 4,5 stroke:#8b5cf6,stroke-width:2px,stroke-dasharray:5 5

    %% Push : pa/pb -> liens 6..7
    linkStyle 6,7 stroke:#f59e0b,stroke-width:3px

    %% Rotations haut : ra/rb -> 8..9 ; rr -> 10..11
    linkStyle 8,9 stroke:#10b981,stroke-width:3px
    linkStyle 10,11 stroke:#0ea5e9,stroke-width:2px,stroke-dasharray:5 5

    %% Rotations bas : rra/rrb -> 12..13 ; rrr -> 14..15
    linkStyle 12,13 stroke:#ef4444,stroke-width:3px
    linkStyle 14,15 stroke:#8b5cf6,stroke-width:2px,stroke-dasharray:5 5
```

### Resume of the program

 *Program Flow (Simplified)*
 
| Step | Action |
| ---- | ------ |
| Parse	| Read options and list of numbers |
| Validate | Check input correctness, duplicates, and option names |
| Options	| Choose algorithm mode (simple, medium, complex, adaptative) |
| ChooseAlgo | Select specific algorithm based on option or input size |
| Algorithm	| Run sorting method (Insertion, ChunkSort, Radix, etc.) |
| ListSort |	Produce final sorted list |
| End |	Exit program |



 *Program Flow (diagram)*

```mermaid
stateDiagram-v2
    [*] --> Parse
    Parse --> Validate: take options and the list of number to sort
    Validate --> Error: If duplicate number or other than int, or wrong options name
    Validate --> Options: check what options is choosed
    Options --> ChooseAlgo
    ChooseAlgo --> Simple: --simple
    ChooseAlgo --> Medium: --medium
    ChooseAlgo --> Complex: --complex
    ChooseAlgo --> Adaptative: --Adaptative
    Options --> Adaptative: If no options 
    Adaptative --> Simple: If n < 25
    Adaptative --> Medium: If n < 100
    Adaptative --> Complex: If n > 100
    Validate --> [*]: Already sorted no return
    Options --> Bench: --bench
    Bench --> ChooseAlgo
    Medium --> Indexing
    Complex --> Indexing
    Simple --> Sort3Number
    Simple --> Sort5Number
    Simple --> InsertionSort
    Indexing --> ChunkSort: If --medium options
    Indexing --> Radix: If --complex options
    ChunkSort --> ListSort
    Radix --> ListSort
    Sort3Number --> ListSort
    Sort5Number --> ListSort
    InsertionSort --> ListSort
    ListSort --> [*]
```


## Resources

**Documentation references used during development:**
- [GeeksforGeeks](https://www.geeksforgeeks.org/)
- IA helped us to understand some algorithms and write the Readme
- [Mermaid](https://www.mermaidchart.com/) - for the graphic in the Readme

