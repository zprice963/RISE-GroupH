# -*- coding: utf-8 -*-
"""
Created on Wed Aug  5 14:28:08 2020

@author: zprice11
"""

import os
import sys

os.environ['OMP_NUM_THREADS'] = '1'
os.environ['NUMEXPR_NUM_THREADS'] = '1'
os.environ['MKL_NUM_THREADS'] = '1'

import numpy as np
from typing import Optional

import params
params = params.Constants()

class Base:
    def __init__(self, g: float, e: float):
        self.g = g
        self.e = e
        
    def set_g(self, new_g: float):
        self.g = new_g
        
    def get_g(self):
        return self.g

    def set_e(self, new_e: float):
        self.e = new_e
        
    def get_e(self):
        return self.e

###########################################
#VOLTAGE-GATED POTASSIUM: M-TYPE CURRENT
###########################################
class M(Base):
    def __init__(self, g: Optional[float]=None, e: float=params.VM):
        super().__init__(g,e)
        
    def I(self, V: float, h: float):
        """
        Calculate current that flows through the channel.

        I = g * m * (V - e)
        m : activation variable (steady state)
        h : inactivation variable
        V : membrane potential
        e : equilibrium potential
        
        Parameters
        ----------
        V : float
            membrane potential
        h : float
            inactivation variable

        Returns
        -------
        float
            current that flows through the channel
        """
        return self.g * self.m_inf(V) * (V-self.e)

###########################################################
#VOLTAGE-GATED POTASSIUM: FAST TRANSIENT A-TYPE CURRENT
###########################################################
class A(Base):
    def __init__(self, g: Optional[float]=None, e: float=params.VA):
        super().__init__(g,e)
        
    def I(self, V: float, h: float):
       """
       Calculate current that flows through the channel.
       
       I = g * m^4 * h * (V - e)
       m : activation variable (steady state)
       h : inactivation variable
       V : membrane potential
       e : equilibrium potential
       
       Parameters
       ----------
       V : float
           membrane potential
       h : float
           inactivation variable

       Returns
       -------
       float
           current that flows through the channel
       """
       return self.g*(self.m_inf(V)**4)*h*(V-self.e)

######################################################
#VOLTAGE-GATED POTASSIUM: DELAYED RECTIFIER CURRENT
######################################################
class KDR(Base):
    def __init__(self, g: Optional[int]=None, e: float=params.VKDR):
        super().__init__(g, e)
        
    def I(self, V: float, n: float):
        """
        Calculate current that flows through the channel.

        I = g * n^nk * (V - e)
        n : activation variable
        V : membrane potential
        e : equilibrium potential

        Parameters
        ----------
        V : float
            membrane potential
        n : float
            activation variable

        Returns
        -------
        float
            current that flows through the channel
        """
        return self.g*(self.n**nk)*(V-self.e)
    
###########################################
# CALCIUM: LOW THRESHOLD T-TYPE CURRENT
########################################### 
class T(Base):
    def __init__(self, g: Optional[int]=None, e: float=params.VCarev):
        super().__init__(g, e)
        
    def I(self, V: float, h: float):
        """
        Calculate current that flows through the channel.
        
        I = g * m^2 * h * (V - e)
        m : activation variable (steady state)
        h : inactivation variable
        V : membrane potential
        e : equilibrium potential

        Parameters
        ----------
        V : float
            membrane potential
        h : float
            inactivation variable

        Returns
        -------
        float
            current that flows through the channel
        """
        return self.g*(self.m_inf(V)**2)*h*(V-self.e)
        
###########################################
# CALCIUM: HIGH THRESHOLD L-TYPE CURRENT
########################################### 
class L(Base):
    def __init__(self, g: Optional[int]=None, e: float=params.VL):
        super().__init__(g, e)
        
    def I(self, V: float, h: float):
        """
        Calculate current that flows through the channel.
        
        I = g * m^2 * h * (V - e)
        m : activation variable (steady state)
        h : inactivation variable
        V : membrane potential
        e : equilibrium potential

        Parameters
        ----------
        V : float
            membrane potential
        h : float
            inactivation variable

        Returns
        -------
        float
            current that flows through the channel
        """
        return self.g*(self.m_inf(V)**2)*h*(V-self.e)

###########################################
# CALCIUM: HIGH THRESHOLD N-TYPE CURRENT
########################################### 
class N(Base):
    def __init__(self, g: Optional[int]=None, e: float=params.VN):
        super().__init__(g, e)
        
    def I(self, V: float, h: float):
        """
        Calculate current that flows through the channel.
        
        I = g * m^2 * h * (V - e)
        m : activation variable (steady state)
        h : inactivation variable
        V : membrane potential
        e : equilibrium potential

        Parameters
        ----------
        V : float
            membrane potential
        h : float
            inactivation variable

        Returns
        -------
        float
            current that flows through the channel
        """
        return self.g*(self.m_inf(V)**2)*h*(V-self.e)

#####################################################################
# CALCIUM-ACTIVATED POTASSIUM: LARGE CONDUNCTANCE CHANNELS CURRENT
#####################################################################
class BK(Base):
    def __init__(self, g: Optional[int]=None, e : float=params.VBK):
        super().__init__(g, e)
        
    def I(self, V: float):
        """
        Calculate current that flows through the channel.
        
        I = g * m * (V - e)
        m : activation variable (steady state)
        V : membrane potential
        e : equilibrium potential

        Parameters
        ----------
        V : float
            membrane potential

        Returns
        -------
        float
            current that flows through the channel
        """
        return self.g * self.m_inf(V) * (V - self.e)

#####################################################################
# CALCIUM-ACTIVATED POTASSIUM: SMALL CONDUNCTANCE CHANNELS CURRENT
#####################################################################
class SK(Base):
    def __init__(self, g: Optional[int]=None, e: float=params.VSK):
        super().__init__(g, e)
        
    def I(self, V: float):
        """
        Calculate current that flows through the channel.
        
        I = g * m * (V - e)
        m : activation variable (steady state)
        V : membrane potential
        e : equilibrium potential

        Parameters
        ----------
        V : float
            membrane potential

        Returns
        -------
        float
            current that flows through the channel

        """
        return self.g * self.m_inf(V) * (V - self.e)
    
###################
# LEAK CURRENT
###################
class Leak(Base):
    def __init__(self, g: Optional[int]=None, e: float=params.VLeak):
        super().__init__(g, e)
        
    def I(self, V: float):
        """
        Calculate current that flows through the channel.
        
        I = g * (V - e)
        V : membrane potential
        e : equilibrium potential

        Parameters
        ----------
        V : float
            membrane potential

        Returns
        -------
        float
            current that flows through the channel
        """
        return self.g * (V - self.e)