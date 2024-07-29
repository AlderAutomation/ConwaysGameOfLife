### Rules  

- Any live cell with fewer than two live neighbours dies (referred to as underpopulation or exposure[2]).  
- Any live cell with more than three live neighbours dies (referred to as overpopulation or overcrowding).  
- Any live cell with two or three live neighbours lives, unchanged, to the next generation.  
- Any dead cell with exactly three live neighbours will come to life.  

### Requirements 

- need a grid  
    - name it World
    - start with 100 X 100 but adjustable  
- need lifeforms with above rules  
    - need to be aware of each other 
- need a game loop with a human readable refresh rate  
