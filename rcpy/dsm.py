import rcpy
from rcpy._dsm import *

CHANNEL_COUNT   = 7
CHANNEL_MIN     = 0
CHANNEL_MAX     = 6

class DSM:

    def __init__(self, channel):
        self.channel = channel

    def get_raw(self):
        return get_raw(self.channel)

    # def get_voltage(self):
    #     return get_voltage(self.channel)
#
# class DC_Jack:
#
#     def get_voltage(self):
#         return get_dc_jack_voltage()
#
# class Battery:
#
#     def get_voltage(self):
#         return get_battery_voltage()

# define adcs
dsm0 = DSM(0)
dsm1 = DSM(1)
dsm2 = DSM(2)
dsm3 = DSM(3)
dsm4 = DSM(4)
dsm5 = DSM(5)
dsm6 = DSM(6)

# list of ADCs, indexed by channel number
dsm = [ dsm0, dsm1, dsm2, dsm3, dsm4, dsm5, dsm6 ]

# dc_jack = DC_Jack()
#
# battery = Battery()
