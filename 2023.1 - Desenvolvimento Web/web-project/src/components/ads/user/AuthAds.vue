<script setup>
import { Auth } from '../../../stores/user.js';
import { Ads } from '../../../stores/ads'
import router from '../../../router';

import ShowUserAds from './ShowUserAds/UserAds.vue'

const user = Auth()
const ads = Ads()




ads.getUserAds(user.id)

console.log(ads.userAnuncios)
function isEmpty(){
    if(ads.userAnuncios.length)
        return true
    else
        return false
}
</script>

<template>
    <ShowUserAds :anuncios="ads.userAnuncios.value" :empty="isEmpty()"/>
</template>