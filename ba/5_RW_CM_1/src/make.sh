#!/bin/sh

cat SignalPair.rebeca StationController.rebeca Train.rebeca Main_mid_two_trains.rebeca > RWCM.rebeca

cd ..
rm -r rmc/
./runrebeca.sh src/RWCM.rebeca TimedRebeca dot src/RWCM.property
