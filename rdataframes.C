void rdataframes() {
	ROOT::RDataFrame df("recoTree", "/afs/cern.ch/work/m/mproffit/public/calratio/signal_HSS_LLP_mH1000_mS50_lt9m_ntuples2016dataAnalysis_paperVersion.root");

	std::cout << "Number of events before cut: " << df.Count().GetValue() << std::endl;
	auto h_HTMiss_before_cut = df.Histo1D({"", ";HTMiss before cut;Number of events", 100, 0.0, 1000.0}, "event_HTMiss");

	auto cut = df.Filter(
		[](const std::vector<double> CalibJet_pT) {
			const auto n_high_pt_jets = std::count_if(
				CalibJet_pT.cbegin(),
				CalibJet_pT.cend(),
				[](const double pt){return pt > 100.0;});
			return n_high_pt_jets >= 2;
		},
		{"CalibJet_pT"}
	);
	std::cout << "Number of events after cut: " << cut.Count().GetValue() << std::endl;
	auto h_HTMiss_after_cut = cut.Histo1D({"", ";HTMiss after cut;Number of events", 100, 0.0, 1000.0}, "event_HTMiss");

	TCanvas c;
	h_HTMiss_before_cut->Draw();
	c.Print("HTMiss_before_cut.png");
	c.Clear();

	h_HTMiss_after_cut->Draw();
	c.Print("HTMiss_after_cut.png");
	c.Clear();
}
