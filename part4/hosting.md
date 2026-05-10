# TĀNTU Fusion Atelier — Web Hosting Selection

## Selected Provider: Wedos Internet, a.s.

**Plan:** WEDOS WebHosting 10 GB SSD  
**Price:** 1 212 CZK/year (approximately 101 CZK/month), billed annually  
**URL:** wedos.cz

---

## Why Wedos

The short answer: Czech company, Czech support, and the best uptime track record of any shared hosting provider operating in the Czech Republic.

Wedos is the largest Czech hosting company by number of hosted domains. Their data centres are physically in Hluboká nad Vltavou (South Bohemia), which matters for page load times — a visitor in Prague or Brno gets response times in the 30–60ms range, not the 200ms+ you see with Western European or US-based providers. For an e-shop where 100ms of extra latency measurably reduces conversion rates, this is not a small detail.

Their uptime guarantee is 99.95%, and independent monitoring by hosting review sites consistently places them above that number. They publish their own real-time uptime statistics, which is unusual and a sign they're confident in the numbers.

For a WordPress + WooCommerce setup the 10 GB SSD plan is appropriate. It includes:

| Feature | Value |
|---|---|
| Disk space | 10 GB SSD |
| MySQL databases | unlimited |
| PHP version | 8.1 / 8.2 (selectable) |
| SSL certificate | free, automatic (Let's Encrypt) |
| Email accounts | unlimited |
| Daily backups | included |
| WordPress auto-installer | included |
| Traffic | unlimited |

WooCommerce with a moderate product catalogue (under 100 SKUs) and moderate traffic (under 5 000 visitors/day) runs comfortably on shared SSD hosting. We don't need a VPS at this stage.

---

## What we considered and rejected

**WebSupport (Slovak provider)** — good option, slightly cheaper at ~85 CZK/month, but support is primarily in Slovak and the data centre is in Bratislava. Load times from Prague are about 40ms slower than Wedos. Ruled out.

**SiteGround (Bulgaria/EU)** — popular internationally, competent WordPress support, but their entry plan is 396 CZK/month (after the first-year discount period), which is four times the Wedos price for roughly the same feature set. No meaningful advantage for a site of this scale. Ruled out.

**Bluehost (US)** — data centre in the US. Average response time from Czech Republic is 180ms. Unacceptable for a local e-shop. Ruled out immediately.

---

## Migration path

If TĀNTU grows to 10 000+ daily visitors or requires dedicated resources (e.g., a custom Node.js API connecting to the e-shop), the natural next step is Wedos's own cloud VPS offering, starting at approximately 350 CZK/month. Staying within the same provider avoids re-pointing DNS and dealing with a new control panel.

---

## Setup notes for the team

1. Register at wedos.cz, select "WebHosting 10 GB SSD", pay annually
2. Point the domain DNS A record to Wedos nameservers (listed in the client zone after registration)
3. Use the Wedos client zone one-click WordPress installer
4. Install WooCommerce plugin from the WordPress plugin directory
5. Upload the child theme files (see visual-style.md for brand assets)
6. SSL activates automatically within 24 hours of DNS propagation

Note: the rip.pef.mendelu.cz server is the submission requirement for the academic project. The hosting selection above reflects what a real business would choose for production deployment.
