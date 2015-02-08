#include "plotwidget.h"

PlotWidget::PlotWidget()
{

    plot=new QwtPlot();
        plot->setTitle( "Plot Demo" );
        plot->setCanvasBackground( Qt::white );
        plot->setAxisScale( QwtPlot::yLeft, 0.0, 10.0);
        plot->insertLegend( new QwtLegend() );

        grid = new QwtPlotGrid();
        grid->attach( plot );

       curve = new QwtPlotCurve();
        curve->setTitle( "Pixel Count" );
        curve->setPen( QColor(Qt::darkGreen));
        curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

       symbol = new QwtSymbol( QwtSymbol::Ellipse,
            QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
        curve->setSymbol( symbol );

        QPolygonF points;
        points << QPointF( 0.0, 4.4 ) << QPointF( 1.0, 3.0 )
            << QPointF( 2.0, 4.5 ) << QPointF( 3.0, 6.8 )
            << QPointF( 4.0, 7.9 ) << QPointF( 5.0, 7.1 );
        curve->setSamples( points );

        curve->attach( plot );





}
