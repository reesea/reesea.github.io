---
layout: page
title: Applied Cybersecurity Projects
description: "Hands-on cybersecurity and information assurance projects demonstrating applied use of security frameworks, vulnerability assessment tools, and secure system design."
permalink: /projects/
---

These projects combine hands-on security tool usage with research-based documentation.
Each activity was performed in a controlled environment to evaluate security mechanisms, analyze results, and connect technical findings to established cybersecurity frameworks.

---

## Framework and Policy Integration

**NIST Cybersecurity Framework (CSF) Implementation Study**  
Designed a practical mapping between CSF Functions and security control families used in enterprise assessment.  
Included creating an organizational *Current vs. Target Profile* and performing a gap analysis using NIST SP 800-53 controls.  
[Read Analysis](/ia/csf-gap-analysis/)

---

**OWASP Top 10 Application Security Overview**  
Documented and tested the OWASP Top 10 2021 vulnerabilities using controlled lab examples.  
Developed mitigation guidance aligned with NIST SP 800-53 and ISO 27034.  
**Tools:** Burp Suite (Community), DVWA, OWASP Juice Shop  
[View Report]({{ '/assets/docs/owasp-top10-overview.pdf' | relative_url }})

---

## Network and Vulnerability Assessment

**OpenVAS (Greenbone) Network Vulnerability Scanning**  
Configured and operated Greenbone Security Assistant for internal and DMZ network scans.  
Created baseline reports showing vulnerability severity distribution and remediation prioritization.  
**Focus:** Network mapping, scan configuration tuning, and interpretation of CVSS metrics.  
[View Summary](#)

---

**Nmap Exploration and Service Enumeration**  
Performed controlled Nmap scans to identify active hosts, open ports, and service versions across segmented lab networks.  
Documented findings, created scan profiles, and explained the impact of timing templates and NSE scripts.  
**Focus:** Ethical network reconnaissance and host discovery methodologies.  
[View Results](#)

---

**Metasploit Framework Demonstration (Controlled Environment)**  
Used Metasploit in a sandboxed lab to demonstrate exploit frameworks, payload handling, and post-exploitation mitigation.  
Focused on understanding exploit structure, privilege escalation prevention, and defensive countermeasures.  
**Note:** All testing conducted within isolated lab VMs for research and educational purposes.  
[Read Documentation](#)

---

## Cryptography and Secure Communication

**Hybrid Cryptographic Protocols Study**  
Analyzed protocols combining symmetric and asymmetric encryption, including SSH, IPsec, and Signal.  
Produced comparative tables of encryption methods, key exchange algorithms, and security guarantees.  
[Read Study](/ia/hybrid-crypto-protocols/)

---

**PGP and S/MIME Email Security Demo**  
Implemented symmetric/asymmetric encryption for secure email exchange using GPG and Thunderbird.  
Documented key generation, signing, and validation workflows, emphasizing usability and certificate trust models.  
[View Documentation](#)
