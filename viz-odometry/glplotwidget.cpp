#include <QtGui>
#include <QtOpenGL>

#include "glplotwidget.h"

GLPlotWidget::GLPlotWidget(QWidget *parent, QGLWidget *shareWidget)
    : QGLWidget(parent, shareWidget)
{
    clearColor = Qt::black;
    xRot = 0;
    yRot = 0;
    zRot = 0;
    currentPos = Matrix::eye(4);
    prevPos=Matrix::eye(4);

}

GLPlotWidget::~GLPlotWidget()
{
}

QSize GLPlotWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLPlotWidget::sizeHint() const
{
    return QSize(200, 200);
}

void GLPlotWidget::rotateBy(int xAngle, int yAngle, int zAngle)
{
    xRot += xAngle;
    yRot += yAngle;
    zRot += zAngle;
    updateGL();
}

void GLPlotWidget::setClearColor(const QColor &color)
{
    clearColor = color;
    updateGL();
}

void GLPlotWidget::updatePlot(Matrix *newPos)
{

    prevPos=currentPos;
    currentPos=*newPos;



}

void GLPlotWidget::initializeGL()
{

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
#ifndef QT_OPENGL_ES_2
    glEnable(GL_TEXTURE_2D);
#endif

#ifdef QT_OPENGL_ES_2

#define PROGRAM_VERTEX_ATTRIBUTE 0
#define PROGRAM_TEXCOORD_ATTRIBUTE 1

    QGLShader *vshader = new QGLShader(QGLShader::Vertex, this);
    const char *vsrc =
        "attribute highp vec4 vertex;\n"
        "attribute mediump vec4 texCoord;\n"
        "varying mediump vec4 texc;\n"
        "uniform mediump mat4 matrix;\n"
        "void main(void)\n"
        "{\n"
        "    gl_Position = matrix * vertex;\n"
        "    texc = texCoord;\n"
        "}\n";
    vshader->compileSourceCode(vsrc);

    QGLShader *fshader = new QGLShader(QGLShader::Fragment, this);
    const char *fsrc =
        "uniform sampler2D texture;\n"
        "varying mediump vec4 texc;\n"
        "void main(void)\n"
        "{\n"
        "    gl_FragColor = texture2D(texture, texc.st);\n"
        "}\n";
    fshader->compileSourceCode(fsrc);

    program = new QGLShaderProgram(this);
    program->addShader(vshader);
    program->addShader(fshader);
    program->bindAttributeLocation("vertex", PROGRAM_VERTEX_ATTRIBUTE);
    program->bindAttributeLocation("texCoord", PROGRAM_TEXCOORD_ATTRIBUTE);
    program->link();

    program->bind();
    program->setUniformValue("texture", 0);

#endif
}

void GLPlotWidget::paintGL()
{
       //qglClearColor(clearColor);
       glClear(  GL_DEPTH_BUFFER_BIT);


        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -10.0f);
        glRotatef(0 / 16.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(0 / 16.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(0 / 16.0f, 0.0f, 0.0f, 1.0f);


//        glBegin(GL_QUADS);

//        glTexCoord2f(0.0f, 0.0f);
//        glVertex2i(0, 0);

//        glTexCoord2f(1.0f, 0.0f);
//        glVertex2i(512, 0);

//        glTexCoord2f(1.0f, 1.0f);
//        glVertex2i(512, 512);

//        glTexCoord2f(0.0f, 1.0f);
//        glVertex2i(0, 512);

//        glEnd();


            qDebug()<<currentPos.val[0][3]<<currentPos.val[2][3];
             qDebug()<<prevPos.val[0][3]<<prevPos.val[2][3];
             glColor3f(1.0f,1.0f,1.0f);
            glBegin(GL_LINES);
                glVertex2f(0,0);
                glVertex2f(currentPos.val[0][3],currentPos.val[2][3]);
            glEnd();
//            glBegin(GL_LINES);
//                glVertex2f(0,0);
//                glVertex2f(60,60);
//            glEnd();

}

void GLPlotWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
       glViewport(0,0,width,height);
       qDebug()<<"Width"<<width;
        qDebug()<<"Height"<<height;

       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
        qDebug()<<"hello resize";

       // glOrtho( 0.0f, width, height, 0.0f, 0.0f, 1.0f);

        glOrtho(-0.5, +0.5, +0.5, -0.5, 4.0, 15.0);

       glMatrixMode(GL_MODELVIEW);


}

void GLPlotWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLPlotWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        rotateBy(8 * dy, 8 * dx, 0);
    } else if (event->buttons() & Qt::RightButton) {
        rotateBy(8 * dy, 0, 8 * dx);
    }
    lastPos = event->pos();
}

void GLPlotWidget::mouseReleaseEvent(QMouseEvent * /* event */)
{
    emit clicked();
}

void GLPlotWidget::makeObject()
{
    static const int coords[6][4][3] = {
        { { +1, -1, -1 }, { -1, -1, -1 }, { -1, +1, -1 }, { +1, +1, -1 } },

    };

    textures[0] = bindTexture
            (QPixmap("/home/mahesh/images/side1.png"), GL_TEXTURE_2D);

     for (int j = 0; j < 4; ++j) {
            texCoords.append
                (QVector2D(j == 0 || j == 3, j == 0 || j == 1));
            vertices.append
                (QVector3D(0.5* coords[0][j][0], 0.5 * coords[0][j][1],
                           0.5 * coords[0][j][2]));
        }

}


