import FWCore.ParameterSet.Config as cms

HcalIsoTrkAnalyzer = cms.EDAnalyzer("HcalIsoTrkAnalyzer",
                                    TrackLabel        = cms.InputTag("generalTracks"),
                                    VertexLabel       = cms.InputTag("offlinePrimaryVertices"),
                                    BeamSpotLabel     = cms.InputTag("offlineBeamSpot"),
                                    EBRecHitLabel     = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
                                    EERecHitLabel     = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
                                    HBHERecHitLabel   = cms.InputTag("hbhereco"),
                                    TriggerEventLabel = cms.InputTag("hltTriggerSummaryAOD","","HLT"),
                                    TriggerResultLabel= cms.InputTag("TriggerResults","","HLT"),
                                    Triggers          = cms.vstring("HLT_IsoTrackHB","HLT_IsoTrackHE"),
                                    TrackQuality      = cms.string("highPurity"),
                                    ProcessName       = cms.string("HLT"),
                                    L1Filter          = cms.string(""),
                                    L2Filter          = cms.string("L2Filter"),
                                    L3Filter          = cms.string("Filter"),
                                    MinTrackPt        = cms.double(10.0),
                                    MaxDxyPV          = cms.double(0.02),
                                    MaxDzPV           = cms.double(0.02),
                                    MaxChi2           = cms.double(5.0),
                                    MaxDpOverP        = cms.double(0.1),
                                    MinOuterHit       = cms.int32(4),
                                    MinLayerCrossed   = cms.int32(8),
                                    MaxInMiss         = cms.int32(0),
                                    MaxOutMiss        = cms.int32(0),
                                    ConeRadius        = cms.double(34.98),
                                    ConeRadiusMIP     = cms.double(14.0),
                                    MinimumTrackP     = cms.double(20.0),
                                    MaximumEcalEnergy = cms.double(2.0),
                                    IsolationEnergy   = cms.double(2.0),
)
