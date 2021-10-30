# Система ОДУ

## Задание

* Параметры системы:

<img src="https://render.githubusercontent.com/render/math?math=p^{atm}=1e-5"> <br>
<img src="https://render.githubusercontent.com/render/math?math=q^{0}=0.001"> <br>
<img src="https://render.githubusercontent.com/render/math?math=l=1"> <br>
<img src="https://render.githubusercontent.com/render/math?math=d=0.01"> <br>
<img src="https://render.githubusercontent.com/render/math?math=\rho=1000"> <br>
<img src="https://render.githubusercontent.com/render/math?math=C_{snd}=1260"> <br>
<img src="https://render.githubusercontent.com/render/math?math=\zeta=1-cos\left({\pi\over 4}\right)"> <br>
<img src="https://render.githubusercontent.com/render/math?math=C={{lS}\over {\rho C^{2}_{snd}}}"> <br>
<img src="https://render.githubusercontent.com/render/math?math=S={{\pi d^2} \over 4}"> <br>


<img src="https://render.githubusercontent.com/render/math?math=\begin{equation*} \begin{cases} q^0t,t \leqslant 1\\ q^0,t>1 \end{cases} \end{equation*}"> <br>

* С помощью двух шагов _**h1**_ и _**h2**_ проинтегрировать систему

<img src="https://render.githubusercontent.com/render/math?math=h1=1e-4"> <br>

<img src="https://render.githubusercontent.com/render/math?math=h2=1e-5"> <br>


<img src="https://render.githubusercontent.com/render/math?math=\begin{equation*} \begin{cases} {{dp_1(t)} \over {dt}} = {{q^n(t)-q_2(t)} \over C} \\ {{dq_2(t)} \over {dt}} = \sqrt{{\zeta|p_1(t)-p^{atm}|} \over {2\rho}} \left({S \sqrt{2|p_1(t)-p^{atm}|} \over {\rho\zeta}} sign \left(p_1(t) - p^{atm}\right) -q_2(t) \right) \end{cases} \end{equation*}"> <br>

```
Интервал интегрирования [0, 20]
```

## Результаты
В качетсве результатов построить графики функций _p(t)_ и _q(t)_

Для всех вариантов интегрирования системы (4 варианта) выдать значения _p(t)_ и _q(t)_ при _t = 10c_