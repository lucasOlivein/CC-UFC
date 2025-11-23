<script setup>
import { computed, watch } from 'vue';

import { Ads } from '../../stores/ads';
import Categories from '../../components/menus/Categories.vue';
import ShowUserAds from '../../components/ads/user/ShowUserAds/UserAds.vue'
import AdminNav from '../../components/menus/AdminNav.vue';
import Headerr from '../../components/header/Header.vue'
import SideMenuVue from '../../components/menus/SideMenu.vue';

const ads = Ads()

function isEmpty(){
    if(ads.filterResult.length == 0){
        return true
    }else
        return false
}
</script>

<template>
    <SideMenuVue/>
    <div class="container">
        <div class="row">
            <Headerr :home="'/admin'" :ads="ads.anuncios" @result="ads.search"/>
        </div>
        <div class="row">
            <div class="col-9">
                <div class="overflow-auto">
                        <ShowUserAds :anuncios="ads.filterResult" :empty="isEmpty()"/>
                </div>
            </div>
            <div class="col-3">
                <div class="mb-4">
                    <AdminNav />
                </div>
                <div class="mt=4">
                    <Categories :In="'/admin/category/'" :Out="'/admin'" :user="true" />
                </div>
            </div>
        </div>
    </div>
</template>