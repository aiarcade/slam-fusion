#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_marker.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_legend.h>

#include <qwt/qwt_text.h>
#include <qwt/qwt_math.h>
#include <qwt/qwt_series_data.h>

#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>


#include<QPen>
class PlotWidget: public QwtPlot
{
public:
    PlotWidget();
private:
      QwtPlot *plot;
      QwtPlotGrid *grid;
       QwtPlotCurve *curve;
       QwtSymbol *symbol;
};




#endif // PLOTWIDGET_H
