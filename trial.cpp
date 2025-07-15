

void trial()
{
    TCanvas *c1 = new TCanvas(); 

    TFile *file = new TFile("PnmuonKE1GeV_10TeV_1PeV.root","READ");                                          
  
    TTree *tree = (TTree*)file->Get("Multiplicity"); //reading out tree
    TH1F *hist = new TH1F("hist", "Muon Energy Distribution for Proton Primary", 100, 0, 5000); 
   //

    double muonE;
    
    // Fill Proton
    tree->SetBranchAddress("muonEnergies", &muonE);
    Long64_t nEntriesP = tree->GetEntries();
    for (Long64_t i = 0; i < nEntriesP; i++) {
        tree->GetEntry(i);
        hist->Fill(muonE);
    }

    hist->SetLineWidth(2);
    hist->SetLineColor(kAzure);
    hist->SetStats(1);
    hist->GetXaxis()->SetLabelFont(62); // axis bold
    hist->GetXaxis()->SetTitleFont(62); // title of the axis
    hist->GetXaxis()->SetTitleOffset(1.4);
    hist->GetYaxis()->SetLabelFont(62); // axis bold
    hist->GetYaxis()->SetTitleFont(62);
    hist->GetYaxis()->SetTitleOffset(1.4);  // Try values like 1.4, 1.6, etc.
    hist->GetYaxis()->CenterTitle();

    hist->GetXaxis()->SetTitle("Muon Kinetic Energy per Shower (GeV)");
    hist->GetYaxis()->SetTitle("Number of Showers");



    hist->Draw(); // First draw the histogram so the stats box is created

    gPad->Update(); // Force canvas to update and stats box to appear

    TPaveStats *stats = (TPaveStats*)hist->FindObject("stats");
    if (stats) {
    stats->SetX1NDC(0.70); // left
    stats->SetX2NDC(0.88); // right
    stats->SetY1NDC(0.66); // bottom
    stats->SetY2NDC(0.86); // top
 // No border
    stats->SetBorderSize(0);
    stats->SetFillColor(0); // Optional: transparent white background
    stats->SetLineColor(0); // Remove outline if any

    //  Remove "hist" name from stats box
    gStyle->SetOptStat(1110); // Entries, Mean, Std Dev only (no name)
   
    stats->SetTextFont(62);
}


    c1->SetLogy();
    c1->Update();
    TFrame *frame = c1->GetFrame();
    frame->SetLineWidth(2);
    frame->SetLineColor(kBlack);
    
    
    
    
    

    //input->Close();
}




