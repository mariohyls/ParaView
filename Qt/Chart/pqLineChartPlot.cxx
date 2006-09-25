/*=========================================================================

   Program: ParaView
   Module:    pqLineChartPlot.cxx

   Copyright (c) 2005,2006 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.1. 

   See License_v1.1.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/

/// \file pqLineChartPlot.cxx
/// \date 9/7/2006

#include "pqLineChartPlot.h"

#include "pqChartCoordinate.h"
#include "pqChartValue.h"


pqLineChartPlot::pqLineChartPlot(QObject *parentObject)
  : QObject(parentObject)
{
}

void pqLineChartPlot::resetPlot()
{
  emit this->plotReset();
}

void pqLineChartPlot::beginInsertPoints(int series, int first, int last)
{
  emit this->aboutToInsertPoints(series, first, last);
}

void pqLineChartPlot::endInsertPoints(int series)
{
  emit this->pointsInserted(series);
}

void pqLineChartPlot::beginRemovePoints(int series, int first, int last)
{
  emit this->aboutToRemovePoints(series, first, last);
}

void pqLineChartPlot::endRemovePoints(int series)
{
  emit this->pointsRemoved(series);
}

void pqLineChartPlot::beginMultiSeriesChange()
{
  emit this->aboutToChangeMultipleSeries();
}

void pqLineChartPlot::endMultiSeriesChange()
{
  emit this->changedMultipleSeries();
}


