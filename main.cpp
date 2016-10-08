#include <QProcess>
#include "EntityWriter.h"
#include "libdxfrw.h"
using namespace std;

void EntityWriter::writeEntities()
{
    #include "input.cpp"
}

    int main()
    {
        dxfRW dxf("./output.dxf");

        EntityWriter writer(dxf);
//       writer.Line(100, 100, 300, 300, "lline", 5);
        dxf.write(&writer, DRW::Version::AC1024, false);
        QProcess::execute("librecad output.dxf");
        return 0;
    }
