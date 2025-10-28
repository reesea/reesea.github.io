---
layout: page
title: "PGP & S/MIME Email Security Demo"
date: 2025-10-25
permalink: /ia/pgp-smime/
description: "Demonstration of encrypted email workflows using GnuPG (OpenPGP) and S/MIME, with key management, signing, and verification guidance."
comments: false
<!-- pandoc: ignore-html -->
---

*Prepared for Applied Information Assurance Projects*  
*Date: October 2025*

---

## 1. Executive summary

This project demonstrates end-to-end email protection using OpenPGP (GnuPG) and S/MIME in a controlled lab. It covers key generation, signing, encryption, verification, and trust models, emphasizing practical usability and operational controls for secure email exchange.

> Scope: Local lab mailboxes and client installations (Thunderbird). All keys and test accounts are laboratory-only and sanitized for publication.

---

## 2. Key concepts

- **OpenPGP / GPG** — user-centric keypairs, web-of-trust or keyserver discovery; flexible but requires user-driven trust decisions.  
- **S/MIME** — X.509 certificates issued by a CA; easier enterprise provisioning but depends on trusted PKI.

Both provide confidentiality and integrity for message bodies; note that standard headers (From, To, Subject) are usually not encrypted.

---

## 3. Lab topology & test setup

- Attacker/Client VM: `user-a-lab.local` (Thunderbird + GPG)  
- Recipient VM: `user-b-lab.local` (Thunderbird + S/MIME cert or GPG key)  
- Optional: Local SMTP/IMAP server for realistic delivery  

The PGP / S-MIME lab was implemented in an isolated virtual network to simulate secure email exchange between two test users. As shown in Figure 1, the environment consists of three primary virtual machines: the *Attacker / Client VM* (`user-a-lab.local`), the *Transport / MTA* server, and the *Recipient VM* (`user-b-lab.local`). This configuration enables end-to-end testing of message signing, encryption, and verification while remaining completely detached from production systems.  

![PGP/S-MIME Lab Topology (isolated)](/assets/images/pgp-flow.png)  

**Figure 1 — PGP / S-MIME Lab Topology (isolated)**  

---

## 4. High-level workflows (sanitized)

To execute the demonstration, both participants generated key pairs, exchanged public keys or certificates, and used Thunderbird to compose, sign, and verify messages. The sanitized command sequence used for these steps is shown in Figure 2 (see Section 5), which details the OpenPGP and S/MIME operations performed through GPG and OpenSSL utilities. These commands were executed only within the isolated environment, using placeholder addresses and self-signed certificates.

### GPG — key generation (example)
```bash
# interactive guided generation (safe)
gpg --full-generate-key

# or non-interactive (replace placeholders)
gpg --batch --gen-key <<'EOF'
Key-Type: RSA
Key-Length: 3072
Name-Real: Test User A
Name-Email: test-a@lab.local
Expire-Date: 1y
%commit
EOF
```

### Export & share public key
```bash
gpg --armor --export test-a@lab.local > test-a.pub.asc
# recipient imports
gpg --import test-a.pub.asc
```

### Sign & encrypt example (local files)
```bash
# sign a file
gpg --armor --sign --output message.sig --detach-sig message.txt

# encrypt for recipient (assumes recipient's public key imported)
gpg --armor --encrypt -r test-b@lab.local -o message.asc message.txt

# decrypt (recipient)
gpg --decrypt message.asc > message.txt
```

## S/MIME — certificate creation (lab CA)
- Create an internal CA, issue client certificates, install into Thunderbird. (Do not publish private keys.)

---

## 5. Thunderbird client flows (visual)

- Generating/importing keys or importing S/MIME certificates.
- Composing a message: toggle Sign and/or Encrypt.
- On receipt: UI indicates Verified signature or Encrypted message; shows certificate details.  

![Sanitized commands](/assets/images/commands-screenshot.png)  

**Figure 2 — Sanitized GPG & S/MIME Commands for Lab Demo**  

_This figure shows the sanitized command-line workflow used for PGP and S/MIME testing.  
All email addresses and key data are placeholders. Do not commit private keys or passphrases._

---

## 6. Usability & trust considerations
- Key discovery: use secure channels / key fingerprints out-of-band. Avoid blindly trusting keyserver imports.
- Revocation & expiry: publish and test revocation procedures (revocation certificates for GPG).
- Certificate trust: S/MIME in enterprises is manageable via internal CA or MDM distribution. Beware of CA compromise risks.

## 7. Operational guidance
- Backup private keys securely (encrypted storage, HSMs for enterprise).
- Use passphrases and consider smartcards or hardware tokens for private key protection.
- Train users on fingerprint verification, phishing resistance, and attachment handling.
- If deploying at scale, automate certificate provisioning (SCEP/AD integration or MDM).

## 8. Limitations & privacy notes
- Email metadata (subject, recipients) is typically visible and must be considered in threat models.
- Encrypted attachments and inline vs PGP/MIME compatibility can affect interoperability.
- Publishing examples uses sanitized keys and truncated fingerprints to avoid exposure.

## 9. References & resources
- GnuPG documentation: [https://gnupg.org](https://gnupg.org)
- Thunderbird encryption guide: [https://support.mozilla.org](https://support.mozilla.org)
- RFC 8551 (OpenPGP), RFC 5751 (S/MIME)
- NIST guidance on cryptographic key management  

<p align="center"> <a href="{{ '/assets/docs/pgp-smime.pdf' | relative_url }}" target="_blank" style="display:inline-block;padding:0.55rem 1rem;background:#268bd2;color:#fff;text-decoration:none;border-radius:6px;"> Download Report (PDF) </a> </p>