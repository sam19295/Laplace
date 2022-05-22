/*
 * File:   poisson.c
 
% Resolviendo la ecuaci�n de Poisson 2-D por la diferencia finita
...M�todo
% El esquema num�rico utilizado es una diferencia central de segundo orden en el espacio
...(diferencia de 5 puntos)

%%
%Especificaci�n de par�metros
nx=80; %N�mero de pasos en el espacio(x)
n = 80; %N�mero de pasos en el espacio(y)
nitro=1000; %N�mero de iteraciones
dx=2/(nx-1); %Ancho del espacio paso(x)
dy=2/(ny-1); %Ancho del espacio paso(y)
x=0:dx:2; %Rango de x(0,2) y especificando los puntos de la cuadr�cula
y=0:dy:2; %Rango de y(0,2) y especificando los puntos de la cuadr�cula
b=ceros(nx,ny); % Preasignaci�n b
pn=ceros(nx,ny); % pn de preasignaci�n


%%
% Condiciones iniciales
p=ceros(nx,ny); % Preasignaci�n p

%%
%Condiciones de borde
p(:,1)=0;
p(:,ny)=0;
p(1,:)=0;
p(nx,:)=0;

%%
%T�rmino fuente
b(redondo(ny/4),redondo(nx/4))=3000;
b(redondo(ny*3/4),redondo(nx*3/4))=-3000;

%%
i=2:nx-1;
j=2:ny-1;
%Esquema iterativo expl�cito con C.D en el espacio (diferencia de 5 puntos)
para it=1:nitro
    pn=p;
    p(i,j)=((dy^2*(pn(i+1,j)+pn(i-1,j)))+(dx^2*(pn(i,j+1)+pn (i,j-1)))-(b(i,j)*dx^2*dy*2))/(2*(dx^2+dy^2));
    %Condiciones de borde
    p(:,1)=0;
    p(:,ny)=0;
    p(1,:)=0;
    p(nx,:)=0;
fin

%%
%Trazar la soluci�n
h=navegar(x,y,p','ColorEdge','ninguno');
interpretaci�n de sombreado
eje ([-0.5 2.5 -0.5 2.5 -100 100])
title({'Ecuaci�n de Poisson 2-D';['{\itN�mero de iteraciones} = ',num2str(it)]})
xlabel('Coordenada espacial (x) \flecha derecha')
ylabel('{\flecha izquierda} Coordenada espacial (y)')
zlabel('Perfil de soluci�n (P) \flecha derecha')
*/