ROOT::RDataFrame df("recoTree", "/afs/cern.ch/work/m/mproffit/public/calratio/signal_HSS_LLP_mH1000_mS50_lt9m_ntuples2016dataAnalysis_paperVersion.root");
auto h_HTMiss = df.Histo1D("event_HTMiss");
TCanvas c;
h_HTMiss->Draw();
h_HTMiss->SetTitle(";HTMiss;Number of events");
auto *x_axis = h_HTMiss->GetXaxis();
x_axis->SetRangeUser(0, 1000);
c.Print("HTMiss.png");
