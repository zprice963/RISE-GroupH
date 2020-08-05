# -*- coding: utf-8 -*-
"""
Created on Wed Aug  5 14:54:28 2020

@author: zprice11
"""

class Constants:
    """
        Constant values needed for model
    """
    def __init__(self) --> None:
        self.VCarev = 60.0
        self.VR = -60.0
        self.VNa = 45.0
        self.VH = -45.0
        self.VK = -93.0
        self.VLeak = -65.0


class TypicalParam:
    """
        Typical parameter set that recapitulates a certain firing pattern
    """
    def __init__(self) --> None:
        self.reg_sws = {
            'gNa': 0.7509,
            'gKDR': 0.0548,
            'gT': 0.11534,
            'gL': 0.0165,
            'gBK': 0.0165,
            'gN': 0.1883,
            'gA': 0.4277,
            'gIH': 0.0023,
            'gSK': 0.004833
            'g_leak': 0.0019688
            }