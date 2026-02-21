<!-- *********************************************************************** -->
<!--                                                                         -->
<!--                                                      :::      ::::::::  -->
<!-- README.md                                          :+:      :+:    :+:  -->
<!--                                                  +:+ +:+         +:+    -->
<!-- By: llugez <llugez@student.42.fr>              +#+  +:+       +#+       -->
<!--                                              +#+#+#+#+#+   +#+          -->
<!-- Created: 2026/02/21 19:32:49 by llugez            #+#    #+#            -->
<!-- Updated: 2026/02/21 19:52:08 by llugez           ###   ########.fr      -->
<!--                                                                         -->
<!-- *********************************************************************** -->

*This project has been created as part of the 42 curriculum by llugez*

# Fractol

## Description

Fractol project asks to reproduce a fractal, but what is a fractal ?\
*In mathematics, a fractal is a geometric shape containing detailed structure at arbitrarily small scales, usually having a fractal dimension strictly exceeding the topological dimension.*[wikipedia](https://en.wikipedia.org/wiki/Fractal)

To simplify that definition for people who are not comfortable with math like me...\
A shape that repeats itself endlessly when you zoom in on it. No matter how much you enlarge it, you continue to see similar patterns.

The project asks us to make 2 different fractals Mandelbrot and Julia set which are two types of fractals.

## Instructions

### Requirements

- **Operating system:** Linux or macOS  
- **Compiler:** `gcc` or `clang`  
- **Make**

### Compilation

To compile the project, run: make\
This will generate a ./fractol binary executable.

There is many compilation arguments you can pass.

./fractol mandelbrot
./fractol julia [-x] [-y]

List of possible arguments for julia:\
  x        y\
[0.0]    [0.8]\
[0.355] [0.355]\
[-0.75] [0.11]\
[-0.8]  [0.156]\
[-0.4]  [0.6]\
[-0.7]  [0.27]\

To clean the project, run:  
`make clean` (<sub>Remove objects files</sub>)\
`make fclean` (<sub>Remove objects files + executable</sub>)\
`make re` (<sub>Full clean and reload</sub>)

### Resources

A great guide to introduce the project, especially the math part[guide](https://medium.com/@jalal92/fractol-22a21a1ad5bd).\
Wikipedia page that explains in depth what is a fractal[pseudo code](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set).
