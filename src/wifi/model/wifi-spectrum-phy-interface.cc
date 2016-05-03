/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 CTTC
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Nicola Baldo <nbaldo@cttc.es>
 */

#include <ns3/ptr.h>
#include <ns3/object.h>
#include <ns3/net-device.h>
#include <ns3/mobility-model.h>
#include <ns3/wifi-phy.h>
#include <ns3/spectrum-phy.h>
#include <ns3/spectrum-signal-parameters.h>
#include <ns3/log.h>
#include <ns3/spectrum-value.h>
#include <ns3/antenna-model.h>

#include "wifi-spectrum-phy-interface.h"
#include "spectrum-wifi-phy.h"

NS_LOG_COMPONENT_DEFINE ("WifiSpectrumPhyInterface");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (WifiSpectrumPhyInterface);

TypeId
WifiSpectrumPhyInterface::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::WifiSpectrumPhyInterface")
    .SetParent<SpectrumPhy> ();
  return tid;
}

WifiSpectrumPhyInterface::WifiSpectrumPhyInterface ()
{
  NS_LOG_FUNCTION (this);
}

void
WifiSpectrumPhyInterface::DoDispose (void)
{
  NS_LOG_FUNCTION (this);
  m_spectrumWifiPhy = 0;
}

void WifiSpectrumPhyInterface::SetSpectrumWifiPhy(Ptr<SpectrumWifiPhy> spectrumWifiPhy)
{
  m_spectrumWifiPhy = spectrumWifiPhy;
}

Ptr<NetDevice>
WifiSpectrumPhyInterface::GetDevice() const
{
  return m_netDevice;
}

Ptr<MobilityModel>
WifiSpectrumPhyInterface::GetMobility()
{
  return m_spectrumWifiPhy->GetMobility ();
}

void
WifiSpectrumPhyInterface::SetDevice (Ptr<NetDevice> d)
{
  m_netDevice = d;
}

void
WifiSpectrumPhyInterface::SetMobility (Ptr<MobilityModel> m)
{
  m_spectrumWifiPhy->SetMobility (m);
}

void
WifiSpectrumPhyInterface::SetChannel (Ptr<SpectrumChannel> c)
{
  NS_LOG_FUNCTION (this << c);
  m_channel = c;
}

Ptr<const SpectrumModel>
WifiSpectrumPhyInterface::GetRxSpectrumModel () const
{
  if (m_txPsd)
    {
      return m_txPsd->GetSpectrumModel ();
    }
  else
    {
      return m_spectrumWifiPhy->GetRxSpectrumModel ();
    }
}

Ptr<AntennaModel>
WifiSpectrumPhyInterface::GetRxAntenna (void)
{
  NS_LOG_FUNCTION (this);
  return m_spectrumWifiPhy->GetRxAntenna ();
}

void
WifiSpectrumPhyInterface::StartRx (Ptr<SpectrumSignalParameters> params)
{
  m_spectrumWifiPhy->StartRx (params);
}


} //namespace ns3
