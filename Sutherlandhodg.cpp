#include<iostream.h>

#include<conio.h>

#include<graphics.h>



int k,xmin,ymin,xmax,ymax,arr[20],m;

void clipl (int x1, int y1, int x2, int y2)

{

    if(x2-x1)

        m=(y2-y1)/(x2-x1);

    else

        m=100000;

    if(x1 >= xmin && x2 >= xmin)

    {

        arr[k]=x2;

        arr[k+1]=y2;

        k+=2;

    }

    if(x1 < xmin && x2 >= xmin)

    {

        arr[k]=xmin;

        arr[k+1]=y1+m*(xmin-x1);

        arr[k+2]=x2;

        arr[k+3]=y2;

        k+=4;

    }

    if(x1 >= xmin  && x2 < xmin)

    {

        arr[k]=xmin;

        arr[k+1]=y1+m*(xmin-x1);

        k+=2;

    }

}



void clipt(int x1, int y1, int x2, int y2)

{

    if(y2-y1)

        m=(x2-x1)/(y2-y1);

    else

        m=100000;

    if(y1 <= ymax && y2 <= ymax)

    {

        arr[k]=x2;

        arr[k+1]=y2;

        k+=2;

    }

    if(y1 > ymax && y2 <= ymax)

    {

        arr[k]=x1+m*(ymax-y1);

        arr[k+1]=ymax;

        arr[k+2]=x2;

        arr[k+3]=y2;

        k+=4;

    }

    if(y1 <= ymax  && y2 > ymax)

    {

        arr[k]=x1+m*(ymax-y1);

        arr[k+1]=ymax;

        k+=2;

    }

}



void clipr(int x1, int y1, int x2, int y2)

{

    if(x2-x1)

        m=(y2-y1)/(x2-x1);

    else

        m=100000;

    if(x1 <= xmax && x2 <= xmax)

    {

        arr[k]=x2;

        arr[k+1]=y2;

        k+=2;

    }

    if(x1 > xmax && x2 <= xmax)

    {

        arr[k]=xmax;

        arr[k+1]=y1+m*(xmax-x1);

        arr[k+2]=x2;

        arr[k+3]=y2;

        k+=4;

    }

    if(x1 <= xmax  && x2 > xmax)

    {

        arr[k]=xmax;

        arr[k+1]=y1+m*(xmax-x1);

        k+=2;

    }

}



void clipb(int x1, int y1, int x2, int y2)

{

    if(y2-y1)

        m=(x2-x1)/(y2-y1);

    else

        m=100000;

    if(y1 >= ymin && y2 >= ymin)

    {

        arr[k]=x2;

        arr[k+1]=y2;

        k+=2;

    }

    if(y1 < ymin && y2 >= ymin)

    {

        arr[k]=x1+m*(ymin-y1);

        arr[k+1]=ymin;

        arr[k+2]=x2;

        arr[k+3]=y2;

        k+=4;

    }

    if(y1 >= ymin  && y2 < ymin)

    {

        arr[k]=x1+m*(ymin-y1);

        arr[k+1]=ymin;

        k+=2;

    }

}

 

void main()

{

    int gd=DETECT,gm,n,poly[20];

    int xi,yi,xf,yf,polyy[20];

    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

    setcolor(WHITE);

    cout<<"Enter the Minimum Coordinates of visible window : x : ";

    cin>>xmin;

    cout<<"y : ";

    cin>>ymin;

    cout<<"Enter the Maximum Coordinates of visible window : x : ";

    cin>>xmax;

    cout<<"y : ";

    cin>>ymax;

    cout<<"Enter the number of side of Polygon to be clipped : ";

    cin>>n;

    cout<<"Enter the coordinates :";

    for(int i=0 ; i < 2*n ; i++)

       cin>>polyy[i];



    polyy[i]=polyy[0];

    polyy[i+1]=polyy[1];

    for(i=0 ; i < 2*n+2 ; i++)

		poly[i]=polyy[i];


    clrscr();

    rectangle(xmin,ymax,xmax,ymin);

    cout<<"\tUNCLIPPED POLYGON";

    setcolor(WHITE);

    fillpoly(n,poly);

	getch();

    clrscr();

    k=0;

    for(i=0;i < 2*n;i+=2)

		clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

    n=k/2;

    for(i=0;i < k;i++)

		polyy[i]=arr[i];

    polyy[i]=polyy[0];

    polyy[i+1]=polyy[1];

    k=0;

    for(i=0;i < 2*n;i+=2)

		clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

    n=k/2;

    for(i=0;i < k;i++)

		polyy[i]=arr[i];

    polyy[i]=polyy[0];

    polyy[i+1]=polyy[1];

    k=0;

    for(i=0;i < 2*n;i+=2)

		clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

    n=k/2;

    for(i=0;i < k;i++)

		polyy[i]=arr[i];

    polyy[i]=polyy[0];

    polyy[i+1]=polyy[1];

    k=0;

    for(i=0;i < 2*n;i+=2)

		clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

    for(i=0;i < k;i++)

		poly[i]=arr[i];

    if(k)

		fillpoly(k/2,poly);

    setcolor(RED);

    rectangle(xmin,ymax,xmax,ymin);

    cout<<"CLIPPED POLYGON";

    getch();

    closegraph();

}



OUTPUT:

minimum coord: x= 200

	y=200

maximum coord: x=400

	y=400

number of sides to be clipped: 3

	coordinates= 150 

	300

	300

	150

	300

	300

	

SECOND OUTPUT:

coordinates: 100

	110

	340

	210

	300

	380
