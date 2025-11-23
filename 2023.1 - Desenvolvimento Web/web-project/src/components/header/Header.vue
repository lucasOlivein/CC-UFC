<script setup>
import router from '../../router';
import { Auth } from '../../stores/user.js';
import { Ads } from '../../stores/ads';
import { ref } from 'vue';
// import SideMenu from '../menus/SideMenu.vue';
const ads = Ads()
const auth = Auth();
const rote = defineProps({ 'home': String, 'ads': Array, 'users':Array })
const emit = defineEmits(['result'])

function getRole() {
    if (auth.role == 'Admin') {
        return 'Admin'
    } else {
        return 'User'
    }
}
function home() {
    ads.categoryAdsButton = false
    router.push(`${rote.home}`)
}


function search(search) {
    const anuncios = []
    console.log(rote.ads)
    if (rote.ads)
        rote.ads.filter(result => result.tittle.toLowerCase().includes(search)).forEach(element => {
            anuncios.push(element)
        })
    else{
        rote.users.filter(result => result.username.toLowerCase().includes(search)).forEach(element => {
            anuncios.push(element)
        })
    }

    emit('result', anuncios)
}

</script>



<template>
    <!-- <SideMenu/> -->
    <nav class="navbar navbar-light bg-light mb-4" id="navbar">
        <div class="container-fluid">


            <button class="btn" @click="home">Ads Qxd</button>
            <form class="d-flex">
                <input id="textBox" class="form-control me-2" @input="search($event.target.value)" type="search"
                    placeholder="Search" aria-label="Search">
                <!-- <button class="btn btn-outline-success" type="button">Search</button> -->
            </form>

            <div v-if="!auth.logged">
                <button class="btn btn-primary mx-2" type="button" data-bs-toggle="offcanvas" data-bs-target="#login"
                    aria-controls="login">Login</button>

                <button class="btn btn-outline-success" type="button" data-bs-toggle="offcanvas"
                    data-bs-target="#register">Register</button>
            </div>


            <div v-else>
                <button class="btn btn-primary mx-2" type="button" data-bs-toggle="offcanvas" data-bs-target="#userOpt"
                    aria-controls="login">{{ getRole() }}</button>
            </div>
        </div>
    </nav>
</template>