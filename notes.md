---
layout: page
title: Notes
description: "Reference notes and study materials from coursework, labs, and cybersecurity readings."
permalink: /notes/
---

Brief reference notes from ongoing cybersecurity coursework and applied information assurance research.  
These entries capture key tools, frameworks, and concepts used across network security, cryptography, and risk management studies.

## Network Security Tools

**Scanning & Enumeration**
- Nmap: Host discovery, port scanning, and service identification  
  nmap -A -T4 192.168.1.0/24  
  nmap --script=vuln target.example.com

- OpenVAS (Greenbone): Vulnerability scanning and CVSS scoring
- Wireshark & Tshark: Packet capture and protocol analysis
- Metasploit (lab use): Exploit framework for controlled, educational penetration testing

### Concepts

- OSI vs. TCP/IP layer mapping
- Defense-in-depth and segmentation
- Vulnerability classes: misconfiguration, exposure, weak encryption

---

## Cryptography

### Core Algorithms

- Symmetric: AES-256, ChaCha20, Twofish
- Asymmetric: RSA-4096, ECDSA, Ed25519
- Hashing & Integrity: SHA-256/512, HMAC, BLAKE2

### Hybrid Protocols
Protocols combining both symmetric and asymmetric encryption:

- TLS 1.3 / QUIC
- SSH
- IPsec / IKEv2
- PGP / S/MIME
- Signal Protocol

[See related study →](/ia/hybrid-crypto-protocols/)

---

## Security Frameworks & Standards

### NIST Core References

- *CSF 2.0* — Identify · Protect · Detect · Respond · Recover
- *SP 800-63* Suite — Digital identity (IAL, AAL, FAL)
- *SP 800-37* — Risk Management Framework
- *SP 800-53 Rev 5* — Security and privacy controls

### Other Frameworks

- *ISO/IEC 27001* — ISMS certification
- *OWASP Top 10 (2021)* — Web app security
- *MITRE ATT&CK* — Threat tactics & techniques

[Explore applied frameworks →](#)

## Risk Management Concepts

### Core Steps

1. Identify assets and data flows
2. Evaluate threats and vulnerabilities
3. Determine likelihood and impact
4. Prioritize and mitigate

### Methods
- CVSS v3.1 scoring for technical findings
- Qualitative heat maps for managerial reporting
- Continuous monitoring via SIEM or GVM feeds

### Example Formula
Risk = Likelihood × Impact

## Reference Library

### Primary
- NIST SP 800-63, 800-53, 800-37, CSF 2.0
- OWASP Testing Guide
- MITRE ATT&CK Matrix

### Supplemental
- *Applied Cryptography* — Bruce Schneier
- *Network Security Essentials* — William Stallings
- *The Web Application Hacker’s Handbook* — Stuttard & Pinto