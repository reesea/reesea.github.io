---
layout: page
title: Applied Information Assurance
description: "Research topics exploring cybersecurity frameworks, risk management, and cryptographic systems."
---

A collection of applied research posts analyzing standards, frameworks, and case studies in Information Assurance and Cybersecurity Management.

Each topic combines academic research with practical implementation insights.

---

{% assign ia_pages = site.pages | where_exp:"p","p.url contains '/ia/'" | where_exp:"p","p.name != 'index.md'" %}
{% assign ia_pages = ia_pages | sort: "date" | reverse %}
<ul>
{% for page in ia_pages %}
  {% if page.title and page.name != "index.md" %}
  <li>
    <a href="{{ page.url | relative_url }}">{{ page.title }}</a><br>
    <span style="font-size:0.9em; color:#666;">
      {{ page.date | date: "%B %d, %Y" }}{% if page.description %} — {{ page.description }}{% endif %}
    </span>
  </li>
  {% endif %}
{% endfor %}
</ul>

---
