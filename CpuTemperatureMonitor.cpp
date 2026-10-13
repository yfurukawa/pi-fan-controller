#include <stdio.h>
#include <stdlib.h>
#include "CpuTemperatureMonitor.h"

CpuTemperatureMonitor::CpuTemperatureMonitor()
{

}

CpuTemperatureMonitor::~CpuTemperatureMonitor()
{

}

double CpuTemperatureMonitor::readCpuTemp()
{
  FILE* fp;
  char buffer[32];
  long temp = 0l;
  fp = fopen( "/sys/class/thermal/thermal_zone0/temp", "r" );

  if( fp == NULL )
  {
//      syslog(LOG_ERR, "Cannot open CPU temperature: %s", strerror(errno) );
      return -1.0;
  }

  if( fgets( buffer, sizeof(buffer), fp ) == NULL )
  {
      fclose( fp );
  //    syslog( LOG_ERR, "Cannot read CPU temperature" );
      return -1.0;
  }
  fclose( fp );

  temp = strtol( buffer, NULL, 10 );

  /*
  * 温度は1000倍されているので度に変換する。
  */
  return (double)temp / 1000.0;
}