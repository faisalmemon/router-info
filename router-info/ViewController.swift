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
        DispatchQueue.global().async {
            var results = ""
            let isBeingDebugged = AmIBeingDebugged()
            results += "Am I being debugged? \(isBeingDebugged)\n"
            if let routes = Route_Info.getRoutes() as? [Route_Info] {
                for item in routes {
                    if let gateway = item.getGateway() {
                        results += "Gateway \(gateway)\n"
                    }
                    if let destination = item.getDestination() {
                        results += "Destination \(destination)\n"
                    }
                    if let netmask = item.getNetmask() {
                        results += "Netmask \(netmask)\n"
                    }
                }
            }
            if let routerIpAddress = Route_Info.getRouterIpAddress() {
                results += "\nRouter IP Address \(routerIpAddress)\n"
            }
            DispatchQueue.main.async {
                self.wiFiInformationTextViewOutlet.text = results
            }
        }
    }
    
    @IBOutlet weak var wiFiInformationTextViewOutlet: UITextView!
    
    override func viewDidLoad() {
        let isBeingDebugged = AmIBeingDebugged()
        print("Am I being debugged? \(isBeingDebugged)")
        
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


}

