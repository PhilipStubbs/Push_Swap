# Push_Swap
 Sort ints in a stack, with a limited set of instructions, using the lowest possible number of actions

The instructions are as followed

| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

I am sorting 500 ints with an average of 8000 instructions.

## bonus visualizer 

By adding the -v flag the following visualizer will be active.

Green lines are in stack A.

Yellow lines are in Stack B.

| The line visualizer |               | 
| ------------- |---------------|
| <img width="740" alt="screen shot 2018-09-12 at 10 22 05" src="https://user-images.githubusercontent.com/24510543/45412084-218bb400-b676-11e8-82b7-ce1db3dfb25f.png">      | <img width="728" alt="screen shot 2018-09-12 at 10 20 16" src="https://user-images.githubusercontent.com/24510543/45412080-20f31d80-b676-11e8-807a-ee3aed0111f4.png"> |
| <img width="735" alt="screen shot 2018-09-12 at 10 21 33" src="https://user-images.githubusercontent.com/24510543/45412083-20f31d80-b676-11e8-8d20-d09950c1276d.png"> |<img width="741" alt="screen shot 2018-09-12 at 10 21 43" src="https://user-images.githubusercontent.com/24510543/45412079-20f31d80-b676-11e8-871f-100ffa3d2420.png">      |

---

By adding the -s flag the following visualizer will be active.

The colour is the last operation completed.

| Stack visualizer    |                    |                    |
| --------------------|--------------------|--------------------|
| <img width="86" alt="screen shot 2018-09-12 at 10 24 46" src="https://user-images.githubusercontent.com/24510543/45412370-b8f10700-b676-11e8-9aa8-b87362a71e7c.png">           | <img width="90" alt="screen shot 2018-09-12 at 10 26 13" src="https://user-images.githubusercontent.com/24510543/45412372-ba223400-b676-11e8-82bf-a235ed894014.png"> | <img width="87" alt="screen shot 2018-09-12 at 10 25 34" src="https://user-images.githubusercontent.com/24510543/45412376-bb536100-b676-11e8-9a8f-98debed1ec8d.png"> |
| <img width="92" alt="screen shot 2018-09-12 at 10 34 31" src="https://user-images.githubusercontent.com/24510543/45412578-46ccf200-b677-11e8-9b3b-1efc553cc751.png">      | <img width="98" alt="screen shot 2018-09-12 at 10 34 52" src="https://user-images.githubusercontent.com/24510543/45412586-492f4c00-b677-11e8-9375-4874491aa101.png">      |   <img width="88" alt="screen shot 2018-09-12 at 10 25 43" src="https://user-images.githubusercontent.com/24510543/45412378-bd1d2480-b676-11e8-89de-f9cc84b05357.png"> |


---
