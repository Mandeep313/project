//																																																																																																																																																	#include "EntityWriter.h"
//EntityWriter::EntityWriter(dxfRW &dxfW) : dxfW(dxfW) {
//}
//void EntityWriter::Line(double a, double b, double c, double d, string layer, double color)
//{
//    DRW_Line line;
//    line.basePoint.x = a;
//    line.basePoint.y = b;
//    line.secPoint.x = c;
//    line.secPoint.y = d;
//    line.layer = layer;
//    line.color = color;
//    dxfW.writeLine(&line);
//}


//void EntityWriter::Point(double x, double y, string layer, double color)

//{
//    DRW_Point BPoint;
//    BPoint.basePoint.x = x;
//    BPoint.basePoint.y = y;
//    BPoint.layer = layer;
//    BPoint.color = color;
//    dxfW.writePoint(&BPoint);
//}

//void EntityWriter::createCircle(double cx, double cy, double radius, string layer, double color)
//{
//    DRW_Circle circle;
//    circle.basePoint.x = cx;
//    circle.basePoint.y = cy;
//    circle.radious = radius;
//    circle.layer = layer;
//    circle.color = color;

//    dxfW.writeCircle(&circle);
//}

//void EntityWriter::Arc(double x, double y, double radius, double staangle, double endangle, string layer, double color)
//{
//    DRW_Arc arc;
//    arc.basePoint.x = x;
//    arc.basePoint.y = y;
//    arc.radious = radius
//    arc.staangle = staangle;
//    arc.endangle = endangle;
//    arc.color = color;
//    arc.layer = layer;
//    dxfW.writeArc(&arc);
//}

//void EntityWriter::Trace(double a, double b, double c, double d, double e, double f, string layer, double color)
//{
//    DRW_Trace trace;
//    trace.basePoint.x = a;
//    trace.basePoint.y = b;
//    trace.secPoint.x = c;
//    trace.secPoint.y = d;
//    trace.thirdPoint.x = e;
//    trace.thirdPoint.y = f;
//    trace.color = color;
//    trace.thickness = 10;
//    trace.layer = layer;
//    dxfW.writeTrace(&trace);

//}

void EntityWriter::wall( double  l,  double  h,  double  cx,  double  cy, string layer,  double  color)
{
    Line(cx, cy, cx+l, cy, layer, color);
    Line(cx+l, cy, cx+l, cy+h, layer, color);
    Line(cx+l, cy+h, cx, cy+h, layer, color);
    Line(cx, cy+h, cx, cy, layer, color);
}

//void EntityWriter::square(double a, double b, double c, double d, string layer, double color)
//{
//    Line(c, d, c+a, d, layer, color);
//    Line(c+a, d, c+a, d+b, layer, color);
//    Line(c+a, d+b, c, d+b, layer, color);
//    Line(c, d+b, c, d, layer, color);

//}


//void EntityWriter::Text(double Height, double Width, string s, double x, double y, string layer, double color)

//{
//    DRW_Text Tex;
//    Tex.height = Height;
//    Tex.widthscale = Width;
//    Tex.text= s;
//    Tex.angle= 0;
//    Tex.oblique= 10;
//    Tex.layer= layer;
//    Tex.basePoint.x = x;
//    Tex.basePoint.y = y;
//    Tex.color = color;
//    dxfW.writeText(&Tex);

//}

//void EntityWriter::wall(double l, double h, double cx, double cy, string layer, double color)
//{
//    Line(cx, cy, cx+l, cy, layer, color);
//    Line(cx+l, cy, cx+l, cy+h, layer, color);
//    Line(cx+l, cy+h, cx, cy+h, layer, color);
//    Line(cx, cy+h, cx, cy, layer, color);
//}

//void EntityWriter::dimension()

//{
//   DRW_DimLinear dim;
//   dim.layer = "dimension";
//   dxfW.writeDimension(&dim);
//}

//DRW_Layer EntityWriter::layer(string name, DRW_LW_Conv::lineWidth lWeight, int color, string linetype)
//{
//    DRW_Layer Layer;
//    Layer.name = name;
//    Layer.lWeight = lWeight;
//    Layer.color = color;
//    Layer.lineType = linetype;
//    dxfW.writeLayer(&Layer);
//    return Layer;
//}



//void EntityWriter::writeEntities()
//{
//    #include "input.cpp"
////Line(12, 34, 45, 65);
////createCircle(100,100,100);
  
// // Line(12, 34, 45, 65);
                                                                        
//}
