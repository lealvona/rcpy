#!/usr/bin/env python3

# Contributed by BrendanSimon

# import rcpy libraries
import rcpy
import rcpy.dsm as dsm

def dsm_test():
    # Read DSM channels via function calls.
    for ch in range(dsm.CHANNEL_COUNT):
        raw = dsm.get_raw(ch)
        # voltage = dsm.get_voltage(ch)
        print("channel={} : raw={:4}".format(ch, raw))

    # Read DSM channels via class instances.
    for ch, a in enumerate(dsm.dsm):
        raw = a.get_raw()
        # voltage = a.get_voltage()
        print("dsm[{}] : raw={:4}".format(ch, raw))

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
    dsm_test()

