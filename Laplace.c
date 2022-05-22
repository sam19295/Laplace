/*
 * File:   Laplace.c
 * 
 % Resolviendo la ecuación de Laplace 2-D por la diferencia finita
...Método
% El esquema numérico utilizado es una diferencia central de segundo orden en el espacio
...(diferencia de 5 puntos)

%%
%Especificación de parámetros
nx=60; %Número de pasos en el espacio(x)
n = 60; %Número de pasos en el espacio(y)
nitro=10000; %Número de iteraciones
dx=2/(nx-1); %Ancho del espacio paso(x)
dy=2/(ny-1); %Ancho del espacio paso(y)
x=0:dx:2; %Rango de x(0,2) y especificando los puntos de la cuadrícula
y=0:dy:2; %Rango de y(0,2) y especificando los puntos de la cuadrícula

%%
%Condiciones iniciales
p=ceros(ny,nx); % Preasignación p
pn=ceros(ny,nx); % pn de preasignación

%%
%Condiciones de borde
p(:,1)=0;
p(:,nx)=y;
p(1,:)=p(2,:); %Condiciones de Neumann
p(ny,:)=p(ny-1,:); ...lo mismo que arriba

%%
%Esquema iterativo explícito con C.D en el espacio (diferencia de 5 puntos)
j=2:nx-1;
i=2:ny-1;
para it=1:nitro
    pn=p;
    p(i,j)=((dy^2*(pn(i+1,j)+pn(i-1,j)))+(dx^2*(pn(i,j+1)+pn (i,j-1))))/(2*(dx^2+dy^2));
    %Condiciones de contorno (condiciones de Neumann)
    p(:,1)=0;
    p(:,nx)=y;
    p(1,:)=p(2,:);
    p(ny,:)=p(ny-1,:);
fin

%%
%Trazar la solución
surf(x,y,p,'ColorEdge','ninguno');
interpretación de sombreado
title ({'Ecuación de Laplace 2-D';['{\itNúmero de iteraciones} = ',num2str(it)]})
xlabel('Coordenada espacial (x) \flecha derecha')
ylabel('{\flecha izquierda} Coordenada espacial (y)')
zlabel('Perfil de solución (P) \flecha derecha')
 */
