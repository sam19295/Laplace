/*
 * File:   Laplace.c
 * 
 % Resolviendo la ecuaci�n de Laplace 2-D por la diferencia finita
...M�todo
% El esquema num�rico utilizado es una diferencia central de segundo orden en el espacio
...(diferencia de 5 puntos)

%%
%Especificaci�n de par�metros
nx=60; %N�mero de pasos en el espacio(x)
n = 60; %N�mero de pasos en el espacio(y)
nitro=10000; %N�mero de iteraciones
dx=2/(nx-1); %Ancho del espacio paso(x)
dy=2/(ny-1); %Ancho del espacio paso(y)
x=0:dx:2; %Rango de x(0,2) y especificando los puntos de la cuadr�cula
y=0:dy:2; %Rango de y(0,2) y especificando los puntos de la cuadr�cula

%%
%Condiciones iniciales
p=ceros(ny,nx); % Preasignaci�n p
pn=ceros(ny,nx); % pn de preasignaci�n

%%
%Condiciones de borde
p(:,1)=0;
p(:,nx)=y;
p(1,:)=p(2,:); %Condiciones de Neumann
p(ny,:)=p(ny-1,:); ...lo mismo que arriba

%%
%Esquema iterativo expl�cito con C.D en el espacio (diferencia de 5 puntos)
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
%Trazar la soluci�n
surf(x,y,p,'ColorEdge','ninguno');
interpretaci�n de sombreado
title ({'Ecuaci�n de Laplace 2-D';['{\itN�mero de iteraciones} = ',num2str(it)]})
xlabel('Coordenada espacial (x) \flecha derecha')
ylabel('{\flecha izquierda} Coordenada espacial (y)')
zlabel('Perfil de soluci�n (P) \flecha derecha')
 */
