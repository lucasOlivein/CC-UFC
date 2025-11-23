<script setup>
import { Ads } from '../../../stores/ads.js';
import ShowAds from './showPublicAds/PublicAds.vue'

const ads = Ads()

ads.getAds()
ads.filterResult = ads.anuncios

</script>

<template>
        <ShowAds :anuncios="ads.filterResult" />
</template>