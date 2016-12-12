Line(80, 40, 150, 90, "line", 2);
Point(50, 30, "point", 6);
Text(20, 0,"Mandeep", 40, 0, "text", 1);
Arc(45, 90, 20, 1.57, 4.17, "arc", 4);
Trace(-95, 0,-50, 0, -70, 40, "trace", 7);
dimension();

square(10,10,10,80,"square",4);
layer("my", DRW_LW_Conv::dxfInt2lineWidth(0), 2, "dot");
wall(100, 100, 160, 20, "wall", 5);

//createCircle(0,20,10, "circle", 3);
    for(int i=0;i<15;i++){
 //createCircle(100,100,100+i*100);
       createCircle(0, 20+i*10, 10, "circle", 3);
   }






