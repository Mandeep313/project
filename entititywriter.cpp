#include "EntityWriter.h"

#include <QFile>
#include <QRegularExpression>
#include <QDebug>
#include <QTextStream>
#include <QIODevice>
#include <QProcess>

EntityWriter::EntityWriter(dxfRW &dxfW) : dxfW(dxfW) {
}

/*
 * Line implementation
 */

void EntityWriter::createLine(int a, int b, int c, int d){
    DRW_Line line;
    line.basePoint.x = a;
    line.basePoint.y = b;
    line.secPoint.x = c;
    line.secPoint.y = d;
    dxfW.writeLine(&line);
}

/*
 * square implementation
 */

void EntityWriter::createLine(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j,){
    DRW_Line square;
    square.basePoint.x = a;
    square.basePoint.y = b;
    square.basePoint.x = c;
    square.basePoint.y = d;
    square.basePoint.x = e;
    square.basePoint.y = f;
    square.basePoint.x = g;
    square.basePoint.y = h;
    square.edgepoint.x = i;
    square.lengthPoint.y = j;
    dxfW.writesquare(&square);
}
/*
 *  Circle implementation
 */

void EntityWriter::createCircle(double cx, double cy, double radius){
    DRW_Circle circle;
    circle.basePoint.x = cx;
    circle.basePoint.y = cy;
    circle.radious = radius;

    dxfW.writeCircle(&circle);
}

/*
 * wall implementation
 */

void EntityWriter::wall(int l, int h, int cx, int cy){
    createLine(cx, cy, cx+l, cy);
    createLine(cx+l, cy, cx+l, cy+h);
    createLine(cx+l, cy+h, cx, cy+h);
    createLine(cx, cy+h, cx, cy);
}

/*
 * Parsing from the input file
 */

void EntityWriter::parse(){
    // reading the input file
    QFile ifile("../in.txt");
    QString content;
    QStringList list;
    ifile.open(QIODevice::ReadOnly);

    // read whole content
    while (!ifile.atEnd()) {
        // defining the regexp by which splitting of contents is to be done
        QRegularExpression exp("(\\(|\\)|\\,|\\=)");
        content = ifile.readAll();
        list = content.split(exp);
        qDebug()<<content;
        qDebug()<<list;
    }
    qDebug()<<"list at the end"<<list;
    // closing the file after reading has been done
    ifile.close();


    // opening the file to write the splitted data
        QFile ofile("out.txt");
        ofile.open(QIODevice::WriteOnly);
        QTextStream out(&ofile);
        out << list.join("\n");
        qDebug()<<"Out is "<<list.join("\n");
        ofile.close();
//            qDebug()<<"Out is "<<out;
        // defining regexp to save only numbers in the parsed data in a list
        //QRegularExpression exp1("^[0-9]*$");

        int count = -1;

        ofile.open(QIODevice::ReadOnly);

        // read whole content
            while (!ofile.atEnd())
            {
                c = ofile.readLine();
                qDebug()<<"c is reading currently :"<<c;
                if(c == "wall\n")
                {
                    ++count;
                    v = new QVector<QString>(5);
                    (*v)[0] = c;
                    qDebug() << "wall";
                    qDebug() <<"v : "<<(*v)[1];
                }
                if(c == "ball\n")
                {
                    ++count;
                    v = new QVector<QString>(4);
                    (*v)[0] = c;
                    qDebug() << "ball";
                }
                if(c == "l\n" && count >= 0 && v != NULL)
                {
                    qDebug() << "l";
                    (*v)[1] = ofile.readLine();

                }
                if(c == "h\n" && count >= 0 && v != NULL)
                {
                    qDebug() << "h";
                    (*v)[2] = ofile.readLine();

                }
                if(c == "bx\n" && count >= 0 && v != NULL)
                        {
                            qDebug() << "bx";
                            (*v)[3] = ofile.readLine();
                        }
                if(c == "by\n" && count >= 0 && v != NULL)
                {
                    qDebug() << "by";
                    (*v)[4] = ofile.readLine();
                }
                if(c == "r\n" && count >= 0 && v != NULL)
                {
                    qDebug() << "r";
                    (*v)[1] = ofile.readLine();
                }
                if(c == "cx\n" && count >= 0 && v != NULL)
                {
                    qDebug() << "cx";
                    (*v)[2] = ofile.readLine();
                }
                if(c == "cy\n" && count >= 0 && v != NULL)
                {
                    qDebug() << "cy";
                    (*v)[3] = ofile.readLine();
                }
                if(c == "\n" && count >= 0 && v != NULL)
                {
                    qDebug() << "v : " << v;
                    bigV.append(v);
                    //delete v;
                    //v = 0;
                }
            }
                    qDebug() <<"bigV count"<< bigV.count();

                    ofile.close();


}


void EntityWriter::writeEntities() {

    /*
     * Calling above entity functions
     */
    createLine(20,20,70,70);
    wall(10,10,90,100);
    wall(100,100,50,10);
    wall(50,40,150,200);
    wall(-50,40,150,200);

    //Creating cylinderical circles.
    for(int i=0;i<15;i++){
//        createCircle(100,100,100+i*100);
        createCircle(500,100+i*10,100);
    }
    for(int i=0;i<15;i++){
//        createCircle(100,100,100+i*100);
        createLine(500,100+i*10,100,100);
    } 
    
    parse();

    wall((*v)[1].toInt(),500,900,100);

    /*
     * polygon doesn't work yet. don't know why
    */
    DRW_Polyline rect;
    rect.basePoint.x = 100;
    rect.basePoint.y = 100;
    rect.defstawidth = 10;
    rect.defendwidth = 100;
    rect.extPoint.x = 150;
    rect.extPoint.y = 150;
    dxfW.writePolyline(&rect);
}
