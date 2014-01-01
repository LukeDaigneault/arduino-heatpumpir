/*
    Fujitsu Nocria (AWYZ14) heatpump control (remote control P/N AR-PZ2)
*/
#ifndef FujitsuHeatpumpIR_h
#define FujitsuHeatpumpIR_h

#include <Arduino.h>
#include <IRSender.h>
#include <HeatpumpIR.h>


// Fujitsu Nocria (AWYZ14) timing constants (remote control P/N AR-PZ2)
#define FUJITSU_AIRCON1_HDR_MARK    3250
#define FUJITSU_AIRCON1_HDR_SPACE   1550
#define FUJITSU_AIRCON1_BIT_MARK    400
#define FUJITSU_AIRCON1_ONE_SPACE   1200
#define FUJITSU_AIRCON1_ZERO_SPACE  390

// Fujitsu codes
#define FUJITSU_AIRCON1_MODE_AUTO  0x00 // Operating mode
#define FUJITSU_AIRCON1_MODE_HEAT  0x04
#define FUJITSU_AIRCON1_MODE_COOL  0x01
#define FUJITSU_AIRCON1_MODE_DRY   0x02
#define FUJITSU_AIRCON1_MODE_FAN   0x03
#define FUJITSU_AIRCON1_MODE_OFF   0xFF // Power OFF - not real codes, but we need something...
#define FUJITSU_AIRCON1_FAN_AUTO   0x00 // Fan speed
#define FUJITSU_AIRCON1_FAN1       0x04
#define FUJITSU_AIRCON1_FAN2       0x03
#define FUJITSU_AIRCON1_FAN3       0x02
#define FUJITSU_AIRCON1_FAN4       0x01


class FujitsuHeatpumpIR : public HeatpumpIR
{
  public:
    FujitsuHeatpumpIR();
    FujitsuHeatpumpIR(const prog_char* model);
    FujitsuHeatpumpIR(const prog_char* model, const prog_char* info);
    void send(IRSender& IR, byte powerModeCmd, byte operatingModeCmd, byte fanSpeedCmd, byte temperatureCmd, byte swingVCmd, byte swingHCmd);

  private:
    void sendFujitsu(IRSender& IR, byte operatingMode, byte fanSpeed, byte temperature);
};

#endif
