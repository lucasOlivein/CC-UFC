<script>
import router from '../../router';
import { Auth } from '../../stores/user.js';
import { Ads } from '../../stores/ads';




export default {
    components: {
    },

    data() {
        return {
            auth: Auth(),
            ads: Ads()
        }
    },
    methods: {
        logged() {
            if (this.ads.role == 'Admin')
                return true
            else
                return false
        },
        getAds() {
            router.push('/admin/ads')
        },
        getUsers() {
            router.push('/admin/users')
        },
    }
}

</script>


<template>
            <div class="container border">
                <div class="row">
                    <button class="btn" @click="getAds()" ref="getAds">
                        <h5>Anuncios</h5>
                    </button>
                </div>
                <div class="row">
                    <button class="btn" @click="getUsers()">
                        <h5>Usuarios</h5>
                    </button>
                </div>
            </div>

</template>