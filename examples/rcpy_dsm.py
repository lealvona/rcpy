#!/usr/bin/env python3

# Contributed by BrendanSimon

# import rcpy libraries
import rcpy
import rcpy.dsm as dsm

def dsm_test():
    # Read DSM channels via function calls.
    for ch in range(1, dsm.CHANNEL_COUNT+1):
        raw = dsm.get_ch_raw(ch)
        # normal = dsm.get_ch_normalized(ch)
        print("channel={} : raw={:4} normal={:+6.2f}".format(ch, raw))

    # Read DSM channels via class instances.
    for ch, a in enumerate(dsm.dsm):
        raw = a.get_ch_raw()
        # normal = a.get_ch_normalized()
        print("dsm[{}] : raw={:4} normal={:+6.2f}".format(ch, raw))

    # Read DC Jack and Battery voltages via function calls.
    # dc_jack_voltage = dsm.get_dc_jack_voltage()
    # battery_voltage = dsm.get_battery_voltage()
    # print("dc-jack : voltage={:+6.2f}".format(dc_jack_voltage))
    # print("battery : voltage={:+6.2f}".format(battery_voltage))
    
    # Read DC Jack and Battery voltages via class instances.
    # dc_jack_voltage = dsm.dc_jack.get_voltage()
    # battery_voltage = dsm.battery.get_voltage()
    # print("dc-jack : voltage={:+6.2f}".format(dc_jack_voltage))
    # print("battery : voltage={:+6.2f}".format(battery_voltage))
        
if __name__ == "__main__":
    while true:
        dsm_test()

