Provides a text filter that turns tokens into embedded tweets. The tweets are generated using the EC webtools social media kit (https://webgate.ec.europa.eu/fpfis/wikis/x/gaUjBg).

# Usage

* enable the module tweetfilter
* on admin/config/content/formats enable the "Embed tweet" filter for any of the text formats
* configure the module at admin/config/content/tweetfilter/settings

To embed a tweet use the tweetfilter token as follows:

    [tweetfilter|type:single|statusid:804232994517090304]

The status ID can be found when sharing a a tweet on twitter.com. For the time being only single tweets can be embedded.

More info
 * EC webtools social media kit (SMK) (https://webgate.ec.europa.eu/fpfis/wikis/x/gaUjBg).
 * EC webtools SMK documention https://webgate.ec.europa.eu/fpfis/wikis/x/kaUjBg.
