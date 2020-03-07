//
//  ViewController.swift
//  router-info
//
//  Created by Faisal Memon on 07/03/2020.
//  Copyright © 2020 Faisal Memon. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBAction func getWiFiInformationButtonAction(_ sender: Any) {
        DispatchQueue.main.async {
            let networkingInformation = routerInfo_getRouterAddress()
            
        }
    }
    
    @IBOutlet weak var wiFiInformationTextViewOutlet: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


}

