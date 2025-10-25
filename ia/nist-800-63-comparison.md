---
layout: post
title: "Comparing NIST SP 800-63-2 and SP 800-63-3: Evolving Assurance Levels for Digital Identity"
date: 2025-09-27
categories: [Information Assurance, Digital Identity]
tags: [NIST SP 800-63, Assurance Levels, Digital Identity, Authentication, IAL AAL FAL]
permalink: /ia/nist-800-63-comparison/
description: "An analysis of how NIST updated the Electronic Authentication Guideline SP 800-63-2 into the SP 800-63-3 suite, introducing separate assurance levels for identity, authentication, and federation to improve digital identity evaluation."
comments: false
---

The NIST SP 800-63 series defines how federal and enterprise systems verify and manage digital identities.
Between 2013 and 2017, NIST transitioned from SP 800-63-2 (Electronic Authentication Guideline) to the SP 800-63-3 Digital Identity Guidelines suite, reflecting a major shift in how *assurance* is conceptualized and applied.  
This comparison outlines the key structural and conceptual updates, focusing on how the newer guidelines better support design and evaluation of digital identity systems.

---

## 1. Context and Purpose

SP 800-63-2 (2013) was designed primarily for *electronic authentication*, emphasizing credential strength and binding between a user and an identity.  
The special publication defined a single, composite Level of Assurance (LOA 1–4) that covered identity proofing, token security, and authentication mechanism robustness.

**SP 800-63-3 (2017)** restructured the guidance into a modular suite:
- **SP 800-63-3** — Core Framework (conceptual overview)  
- **SP 800-63A** — *Enrollment and Identity Proofing*  
- **SP 800-63B** — *Authentication and Lifecycle Management*  
- **SP 800-63C** — *Federation and Assertions*

This modular design allows agencies and organizations to tailor assurance requirements to specific use cases (e.g., onboarding vs. login vs. federation).

---

## 2. Shift from LOA to IAL, AAL, and FAL

| Framework | Pre-2017 (SP 800-63-2) | Post-2017 (SP 800-63-3 Suite) |
|------------|------------------------|--------------------------------|
| **Structure** | Single document | Four-part suite (63-3 Core, A, B, C) |
| **Assurance Model** | Composite LOA 1–4 | Three separate dimensions: IAL, AAL, FAL |
| **Focus** | Authentication strength | Identity proofing, authentication, federation |
| **Flexibility** | One-size-fits-all LOA | Modular assurance per component |
| **User Experience** | Rigid token and credential rules | Risk-based, user-centric, allows MFA and federation |

*Table 1. Key changes in assurance structure between SP 800-63-2 and SP 800-63-3.*

The **three-tiered assurance model** in SP 800-63-3 disaggregates assurance into:

- **IAL – Identity Assurance Level:** Confidence in the identity proofing process.  
- **AAL – Authenticator Assurance Level:** Strength of the authentication mechanism (passwords, tokens, MFA).  
- **FAL – Federation Assurance Level:** Confidence in assertion integrity between systems.

This separation allows systems to apply different assurance strengths depending on context, for example, IAL 2 + AAL 3 + FAL 1 for high-risk federal applications.

---

## 3. Improvements in Design and Evaluation

1. **Risk-based flexibility:**  
   SP 800-63-3 explicitly promotes a risk-assessment approach rather than prescriptive rules, aligning with NIST SP 800-37 (RMF) and SP 800-30 (risk analysis).

2. **User experience awareness:**  
   The newer guidelines acknowledge usability and accessibility, a major pain point under SP 800-63-2, which often prioritized technical strength over practicality.

3. **Support for modern technologies:**  
   Incorporates federation, biometrics, and MFA, and aligns with FIDO2/WebAuthn, which were not addressed in SP 800-63-2.

4. **Lifecycle perspective:**  
   SP 800-63-3 addresses credential lifecycle management, recovery, and revocation, making evaluation continuous rather than one-time.

5. **Alignment with privacy principles:**  
   The new framework embeds privacy considerations (linkage minimization, attribute disclosure, consent), reflecting OMB M-19-17.

---

## 4. Example: Applying the New Model to a University Login System

| Component | Example Implementation | Applicable Assurance Level |
|------------|-----------------------|-----------------------------|
| **Identity Proofing (IAL)** | Verification via student ID + official documents | IAL 2 |
| **Authentication (AAL)** | Password + time-based OTP | AAL 2 |
| **Federation (FAL)** | SAML assertion with signed token | FAL 2 |

This modular configuration achieves the same overall assurance as LOA 3 under the old system but with greater flexibility and clearer accountability across lifecycle stages.

---

## 5. Impact on System Evaluation

The SP 800-63-3 suite simplifies evaluation by letting auditors and system owners:
- Measure each dimension independently (proofing vs. authentication).  
- Reuse federated assurance assertions between agencies.  
- Align with FedRAMP and OMB identity directives more efficiently.  
- Quantify risk reduction per control type, improving documentation and traceability.

In effect, the special publication transforms digital identity management from a compliance checklist into a continuous assurance process.

---

## 6. Conclusion

The move from SP 800-63-2 to the SP 800-63-3 suite represents a paradigm shift from a monolithic assurance model to a modular, risk-based framework.
By distinguishing identity proofing, authentication, and federation, organizations can design systems that are both more secure and more adaptable to evolving technology and policy landscapes.

This flexibility not only enhances interoperability between agencies but also better supports usability, privacy, and the long-term sustainability of digital identity ecosystems.

---

## References

1. *National Institute of Standards and Technology (2013).* SP 800-63-2: Electronic Authentication Guideline.
   https://doi.org/10.6028/NIST.SP.800-63-2  
2. *National Institute of Standards and Technology (2017).* <br>SP 800-63-3 Digital Identity Guidelines Suite.
   https://pages.nist.gov/800-63-3/  
3. *Office of Management and Budget (2019).* M-19-17: Enabling Mission Delivery through Improved Identity, Credential, and Access Management (ICAM).
4. University of Wisconsin–Madison. *User Authentication and Levels of Assurance.*  
   https://www.cio.wisc.edu/security/about/campus-initiatives/user-authentication-levels-assurance  

---

> *Originally researched September 2025 for Information Assurance discussion on evolving NIST digital identity assurance models.*
