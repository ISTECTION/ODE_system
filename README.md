# Система ОДУ

## Задание

* Параметры системы:
$$p^{атм}=1e-5$$
$$q^{0}=0.001$$
$$l=1$$
$$d=0.01$$
$$\rho=1000$$
$$C_{snd}=1260$$
$$\zeta=1-cos\left({\pi\over 4}\right)$$
$$C={lS\over \rho C^{2}_{snd}}$$
$$S={\pi d^2 \over 4}$$


$$\begin{equation*}
q^n(t)=
    \begin{cases}
        q^0t,\;t \leqslant 1\\
        q^0,\;\;t>1
    \end{cases}
\end{equation*}$$


* С помощью двух шагов _**h1**_ и _**h2**_ проинтегрировать систему
$$h1=1e-4$$
$$h2=1e-5$$


![equation](http://www.sciweavers.org/tex2img.php?eq=%5Cbegin%7Bequation%2A%7D%0A%20%20%20%20%5Cbegin%7Bcases%7D%0A%20%20%20%20%20%20%20%20%7Bdp_1%28t%29%20%5Cover%20dt%7D%20%3D%20%7Bq%5En%28t%29-q_2%28t%29%20%5Cover%20C%7D%5C%5C%0A%20%20%20%20%20%20%20%20%7Bdq_2%28t%29%20%5Cover%20dt%7D%20%3D%20%7B%5Csqrt%7B%5Czeta%7Cp_1%28t%29-p%5E%7B%D0%B0%D1%82%D0%BC%7D%7C%20%5Cover%202%5Crho%7D%20%5Cleft%28S%20%5Csqrt%7B2%7Cp_1%28t%29-p%5E%7B%D0%B0%D1%82%D0%BC%7D%7C%20%5Cover%20%5Crho%5Czeta%7D%20sign%20%5Cleft%28p_1%28t%29%20-%20p%5E%7B%D0%B0%D1%82%D0%BC%7D%5Cright%29%20-q_2%28t%29%20%5Cright%29%20%20%7D%0A%20%20%20%20%5Cend%7Bcases%7D%0A%5Cend%7Bequation%2A%7D&bc=Transparent&fc=Black&im=png&fs=18&ff=mathdesign&edit=0)


$$\begin{equation*}
    \begin{cases}
        {dp_1(t) \over dt} = {q^n(t)-q_2(t) \over C}\\
        {dq_2(t) \over dt} = {\sqrt{\zeta|p_1(t)-p^{атм}| \over 2\rho} \left(S \sqrt{2|p_1(t)-p^{атм}| \over \rho\zeta} sign \left(p_1(t) - p^{атм}\right) -q_2(t) \right)  }
    \end{cases}
\end{equation*}$$


```
Интервал интегрирования [0, 20]
```

## Результаты
В качетсве результатов построить графики функций _p(t)_ и _q(t)_

Для всех вариантов интегрирования системы (4 варианта) выдать значения _p(t)_ и _q(t)_ при _t = 10c_