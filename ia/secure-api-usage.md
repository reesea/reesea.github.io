---
layout: page
title: "Secure API Usage Guide: Postman & curl (Applied IA Perspective)"
date: 2026-04-01
description: "A practical guide to secure API usage using curl and Postman, covering authentication methods, common security risks, and best practices aligned with Applied Information Assurance (CI4A) principles."
permalink: /ia/secure-api-usage/
comments: false
<!-- pandoc: ignore-html -->
---

## 1. Overview

APIs are the backbone of modern applications, enabling communication between services, clients, and external platforms. However, insecure API usage is a common entry point for attacks such as credential leakage, unauthorized access, and data exposure.

This guide demonstrates how to securely interact with APIs using `curl` and Postman, while mapping each practice to Applied Information Assurance (IA) principles.

## 2. Secure API Flow Overview (diagram)

As shown in **Figure 1**, secure API usage involves multiple layers including client request handling, authentication, authorization, and logging. Each component plays a role in enforcing confidentiality, integrity, and accountability.

[![Secure API Usage Flow](/assets/images/secure-api-flow.png)](/assets/images/secure-api-flow.png)
**Figure 1 — Secure API Usage Flow (isolated demonstration)**

The diagram illustrates how requests flow from the client through authentication and API processing layers, with TLS protecting data in transit and logging supporting auditability.

This flow supports CI4A principles by ensuring confidentiality through TLS, authentication via tokens, authorization through scoped access, and accountability through logging.

## 3. Threat Model

Before using an API, it is important to understand common risks:

- Exposed API keys (hardcoded or committed to repositories)
- Man-in-the-middle (MITM) attacks over unsecured connections
- Replay attacks using intercepted tokens
- Over-permissioned tokens granting excessive access

## 4. Authentication Methods

### API Keys
- Simple but risky if exposed
- Should never be hardcoded or shared

### Bearer Tokens (JWT)

Used in headers:
```bash
curl -H "Authorization: Bearer <token>"
```

### OAuth (conceptual)
- Delegated authorization
- Tokens issued with scoped permissions

## 5. Secure API Usage with curl

### Use HTTPS Only
```bash
curl https://api.example.com/data
```

### Pass Tokens via Headers (not URL)
```bash
export TOKEN="your_token_here"

curl https://api.example.com/data \
  -H "Authorization: Bearer $TOKEN"
```

### Avoid Shell History Leaks
- Do not paste secrets directly into commands
- Use environment variables (`$TOKEN`)

### Example: Secure vs Insecure API Call

Insecure:
```bash
curl "http://api.example.com/data?apikey=12345"
```

Secure:
```bash
export TOKEN="secure_token"

curl https://api.example.com/data \
  -H "Authorization: Bearer $TOKEN"
```

Misconfigured API authentication has been a contributing factor in 
multiple data breaches, often due to exposed tokens or lack of transport security.

## 6. Secure API Usage with Postman
### Use Environment Variables
- Store tokens in variables (e.g., ```{{ token }}```)
- Avoid hardcoding credentials in requests

### Token Handling
- Use pre-request scripts for dynamic tokens
- Do not export collections with active secrets

### Example Header in Postman
```bash
Authorization: Bearer {{token}}
```

## 7. Common Mistakes
- Hardcoding API keys in source code
- Using HTTP instead of HTTPS
- Logging sensitive headers (Authorization tokens)
- Sharing Postman collections with live credentials
- Using overly broad permissions

## 8. Mitigations & Best Practices
- Use .env files or secure vaults
- Rotate API keys regularly
- Apply least privilege (scoped tokens)
- Validate TLS certificates
- Monitor API usage logs

## 9. Mapping to CI4A Principles

| Principle       | Application in API Security   |
|-----------------|-------------------------------|
| Confidentiality | TLS (HTTPS), token protection |
| Integrity       | Signed requests, hashing      |
| Authentication  | API keys, JWT, OAuth          |
| Authorization   | Scopes, role-based access     |
| Accountability  | Logging, request tracing      |

## 10. Conclusion
Secure API usage is not optional, it is a core component of system design. 
By applying proper authentication, protecting credentials, and enforcing least privilege, developers can significantly reduce risk.

These practices align directly with Applied Information Assurance principles and help ensure systems remain resilient against common attack vectors.

This approach reflects a system-first mindset, where security is integrated into API design rather than added after deployment.
