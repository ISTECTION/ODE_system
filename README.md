# Сисьема ОДУ

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